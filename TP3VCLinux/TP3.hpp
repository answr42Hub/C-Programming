#include "Stack.hpp"
#include <vector>
#include "BSTree.hpp"
//#include "AVLTree"
#include "Folder.hpp"

using namespace std;
string title;
string name;
int indx;
Stack<Folder*>* path;
BSTree<int>* selections;
Queue<int>* indexSorted;
//AVLTree<int>* selections;

// Fonction retournant l'index d'un element
int getIndex(const int& x, const int& y) {
	// TODO : Retourner l'indice de l'élément clické
	if(path->size() > 1)
		return ((y/Window::getIconHeight())*(Window::getWidth()/Window::getIconWidth()) + x/Window::getIconWidth())-1;
	else
		return ((y/Window::getIconHeight())*(Window::getWidth()/Window::getIconWidth()) + x/Window::getIconWidth());
}

//Fonction retournant le nom du fichier tronqué
string trunkName(string name) {
	while((Window::getStringWidth(name) + Window::getStringWidth("...")) > Window::getIconWidth()) {
		name.pop_back();
	}
	name += "...";
	return name;
}

// Methode pour supprimer un element selon son indexe
void deleteElement(int elementIndex) {
	if(elementIndex < path->top()->getFolderCount())
		path->top()->deleteFolder(elementIndex);
	else if(elementIndex < path->top()->getNoteCount()+path->top()->getFolderCount()) {
		elementIndex -= (path->top()->getFolderCount());
		path->top()->deleteNote(elementIndex);
	}
}

//Fonctions qui verifie si le nom de dossier ou de note existe
bool folderExists(string name) {
	for(int i = 0; i < path->top()->getFolderCount(); i++) {
		if(path->top()->getFolder(i)->getFolderName() == name)
			return true;
	}
	return false;
}
bool noteExists(string name) {
	for(int i = 0; i < path->top()->getNoteCount(); i++) {
		if(path->top()->getNote(i)->getName() == name)
			return true;
	}
	return false;
}

void onInit() {
	// TODO : Initialisations
	title = "/";
	path = new Stack<Folder*>();
	selections = new BSTree<int>();

	path->push(new Folder("/"));

	path->top()->createFolder("ZZtop");
	path->top()->createFolder("Alfredo");
	path->top()->createFolder("KindaCringeeeeeeeeeeeeeeee");
	path->top()->createFolder("AAAAAA 4");
	path->top()->createFolder("Dossier 5");
	path->top()->createFolder("Dossier 6");
	path->top()->createFolder("FOLDERSS");
	path->top()->createFolder("Dossier 8");
	path->top()->createNote("Note 5");
	path->top()->createNote("Note 2");
	path->top()->createNote("Note 6666666666666666666");
	path->top()->createNote("Note 4");
	path->top()->createNote("Note 1");
	path->top()->createNote("Note 3");
	path->top()->getFolder(0)->createFolder("Hello !");
	path->top()->getFolder(0)->createNote("Hello !note");
}

void onRefresh() {
	// TODO : Afficher le contenu du dossier actuel
	int x = 0, y = 0;
	
	if(path->size() > 1) {
		Window::drawIcon(FOLDER, x, y);

		Window::drawString("..", (Window::getIconWidth() - Window::getStringWidth(".."))/2 + x, (Window::getIconHeight() + y) - 25);
		x+=Window::getIconWidth();
	}
	//Afficher les dossiers
	for (int i = 0; i < path->top()->getFolderCount(); i++) {
		if(x + Window::getIconWidth() >= Window::getWidth()) {
			y+=Window::getIconHeight();
			x=0;
		}

		name = path->top()->getFolder(i)->getFolderName();

		if(Window::getStringWidth(name) > Window::getIconWidth()) {
			name = trunkName(name);
		}

		Window::drawIcon(FOLDER, x, y, selections->search(getIndex(x, y)));
		
		Window::drawString(name, (Window::getIconWidth() - Window::getStringWidth(name))/2 + x, (Window::getIconHeight() + y) - 25);

		x+=Window::getIconWidth();
	}
	//Afficher les notes
	for (int j = 0; j < path->top()->getNoteCount(); j++) {
		if(x + Window::getIconWidth() >= Window::getWidth()) {
			y+=Window::getIconHeight();
			x=0;
		}

		name = path->top()->getNote(j)->getName();

		if(Window::getStringWidth(name) > Window::getIconWidth()) {
			name = trunkName(name);
		}

		Window::drawIcon(NOTE, x, y, selections->search(getIndex(x, y)));
		Window::drawString(name, (Window::getIconWidth() - Window::getStringWidth(name))/2 + x, (Window::getIconHeight() + y) - 25);

		x+=Window::getIconWidth();
	}
	//Afficher les notes encodees
	//bonus
}

void onWindowClick(const int& x, const int& y, const bool& button, const bool& ctrl) {
	indx = getIndex(x, y);
	
	if(button && ctrl) {
		
		if(!selections->search(indx)) {
			selections->add(indx);
		}
		else {
			selections->remove(indx);
		}
	}

	else if (button) {
		// TODO : Click sur un dossier ou une note du dossier actuel
		
		if(indx == -1) {
			if(path->size() == 2) {
				for(int i = 0; i < path->top()->getFolderName().size(); i++) 
					title.pop_back();	
			}
			else {
				for(int i = 0; i < path->top()->getFolderName().size()+1; i++) 
					title.pop_back();
			}
			path->pop();
			Window::setTitle(title);
		}
		else if(path->top()->getFolderCount() && indx <= path->top()->getFolderCount()-1) {
			if(path->size() > 1)
				title+="/";
			path->push(path->top()->getFolder(indx));
			title += path->top()->getFolderName();
			Window::setTitle(title);
		}
		else if(path->top()->getNoteCount() && indx-(path->top()->getFolderCount()) <= path->top()->getNoteCount()-1) {
			indx -= (path->top()->getFolderCount());
			path->top()->getNote(indx)->setNoteContent(Window::showTextField(path->top()->getNote(indx)->getContent()));
		}

		selections->clear();
		
	}

	else {
		// TODO : Afficher le menu
		if(indx != -1) {
			if(indx < (path->top()->getFolderCount()+path->top()->getNoteCount()))
				Window::showMenu(x, y, Menu::RENAME | Menu::DELETE | Menu::ENCODE | Menu::DECODE | Menu::SELECT_ALL);
			else
				Window::showMenu(x, y, Menu::NEW_FOLDER | Menu::NEW_NOTE | Menu::DELETE | Menu::SELECT_ALL);
		}
	}
}

void onMenuClick(const unsigned int& menuItem) {
	switch (menuItem) {
	case Menu::NEW_FOLDER: {
		// TODO : Créer un nouveau dossier dans le dossier actuel
		name = Window::showTextField("New Folder");
		if(name != "" && !folderExists(name)) {
			path->top()->createFolder(name);
		}
		break;
	}
	case Menu::NEW_NOTE: {
		// TODO : Créer une nouvelle note dans le dossier actuel
		name = Window::showTextField("New Note");
		if(name != "" && !noteExists(name)) {
			path->top()->createNote(name);
		}
		break;
	}
	case Menu::RENAME:
		// TODO : Renommer le dossier ou la note
		if(indx < path->top()->getFolderCount()) {
			name = Window::showTextField(path->top()->getFolder(indx)->getFolderName());
			if(!folderExists(name))
				path->top()->getFolder(indx)->setFolderName(name);
		}
		else if(indx < path->top()->getNoteCount()+path->top()->getFolderCount()) {
			name = Window::showTextField(path->top()->getNote(indx-path->top()->getFolderCount())->getName());
			if(!noteExists(name))
				path->top()->getNote(indx-path->top()->getFolderCount())->setNoteName(name);
			
		}
		break;

	case Menu::DELETE:
		// TODO : Supprimer le ou les dossiers, et tout ce qu'ils contiennent, et la ou les notes sélectionnés
		
		indexSorted = selections->traversal(Infix);
		if(selections->size()) {
			while(indexSorted->size()) {
				deleteElement(indexSorted->front());
				indexSorted->pop();
			}
		}
		else {
			deleteElement(indx);
		}
		delete indexSorted;
		selections->clear();
		break;

	case Menu::ENCODE:
		// TODO : Encoder la note avec la méthode de Huffman
		break;

	case Menu::DECODE:
		// TODO : Décoder la note avec la méthode de Huffman
		break;

	case Menu::SELECT_ALL:
		// TODO : Sélectionner tous les dossiers et notes du dossier actuel
		// Methode pour tout selectionner

		for(int i = 0; i < (path->top()->getFolderCount()+path->top()->getNoteCount()); i++) {
			if(!selections->search(i))
				selections->add(i);
		}

		break;
	}
}

void onQuit() {
	// TODO : Libérations
	
	while(path->size()) {
		if(path->size() == 1) {
			delete path->top();
		}
		else {
			while(path->top()->getFolderCount() + path->top()->getNoteCount()) {
				deleteElement((path->top()->getFolderCount() + path->top()->getNoteCount())-1);
			}
		}
		
		path->pop();
	}
	delete path;
	selections->clear();
	delete selections;
	
}