#include "Stack.hpp"
#include <vector>
#include <deque>
#include "BSTree.hpp"
//#include "AVLTree"
#include "Folder.hpp"

using namespace std;
string title;
int indx;
Stack<Folder*>* path;
//AVLTree<int>* selections;

int getIndex(const int& x, const int& y) {
	// TODO : Retourner l'indice de l'élément clické
	if(path->size() > 1)
		return ((y/Window::getIconHeight())*(Window::getWidth()/Window::getIconWidth()) + x/Window::getIconWidth())-1;
	else
		return ((y/Window::getIconHeight())*(Window::getWidth()/Window::getIconWidth()) + x/Window::getIconWidth());
}

void onInit() {
	// TODO : Initialisations
	title = "/";
	path = new Stack<Folder*>();
	
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

//Fonction retournant le nom du fichier tronqué
string trunkName(string name) {
	while((Window::getStringWidth(name) + Window::getStringWidth("...")) > Window::getIconWidth()) {
		name.pop_back();
	}
	name += "...";
	return name;
}

void onRefresh() {
	// TODO : Afficher le contenu du dossier actuel
	//Faire une boucle pour afficher tous les dossiers et notes selon la largeur de la fenetre
	int x = 0, y = 0;
	string name;
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

		Window::drawIcon(FOLDER, x, y);
		
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

		Window::drawIcon(NOTE, x, y);
		Window::drawString(name, (Window::getIconWidth() - Window::getStringWidth(name))/2 + x, (Window::getIconHeight() + y) - 25);

		x+=Window::getIconWidth();
	}
	//Afficher les notes encodees
	//bonus
}

void onWindowClick(const int& x, const int& y, const bool& button, const bool& ctrl) {
	indx = getIndex(x, y);
	if (button) {
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
	}

	else {
		// TODO : Afficher le menu
		if(indx != -1) {
			if(indx < (path->top()->getFolderCount()+path->top()->getNoteCount()))
				Window::showMenu(x, y, Menu::RENAME | Menu::DELETE | Menu::ENCODE | Menu::DECODE | Menu::SELECT_ALL);
			else
				Window::showMenu(x, y, Menu::NEW_FOLDER | Menu::NEW_NOTE | Menu::SELECT_ALL);
		}
	}
}

void onMenuClick(const unsigned int& menuItem) {
	switch (menuItem) {
	case Menu::NEW_FOLDER:
		// TODO : Créer un nouveau dossier dans le dossier actuel
		path->top()->createFolder(Window::showTextField("New Folder"));
		break;

	case Menu::NEW_NOTE:
		// TODO : Créer une nouvelle note dans le dossier actuel
		path->top()->createNote(Window::showTextField("New Note"));
		break;

	case Menu::RENAME:
		// TODO : Renommer le dossier ou la note
		if(indx < path->top()->getFolderCount())
			path->top()->getFolder(indx)->setFolderName(Window::showTextField(path->top()->getFolder(indx)->getFolderName()));
		else if(indx < path->top()->getNoteCount()+path->top()->getFolderCount())
			path->top()->getNote(indx-path->top()->getFolderCount())->setNoteName(Window::showTextField(path->top()->getNote(indx-path->top()->getFolderCount())->getName()));
		break;

	case Menu::DELETE:
		// TODO : Supprimer le ou les dossiers, et tout ce qu'ils contiennent, et la ou les notes sélectionnés
		
		break;

	case Menu::ENCODE:
		// TODO : Encoder la note avec la méthode de Huffman
		break;

	case Menu::DECODE:
		// TODO : Décoder la note avec la méthode de Huffman
		break;

	case Menu::SELECT_ALL:
		// TODO : Sélectionner tous les dossiers et notes du dossier actuel
		break;
	}
}

void onQuit() {
	// TODO : Libérations
}