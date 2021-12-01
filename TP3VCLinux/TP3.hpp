#include "Stack.hpp"
#include <vector>
#include <deque>
//#include "BSTree.hpp"
//#include "AVLTree"
#include "Folder.hpp"

using namespace std;

Stack<Folder*>* path;
//AVLTree<int>* selections;

int getIndex(const int& x, const int& y) {
	// TODO : Retourner l'indice de l'élément clické
	return -1;
}

void onInit() {
	// TODO : Initialisations
	path = new Stack<Folder*>();
	path->push(new Folder("/"));

	path->top()->creatFolder("ZZtop");
	path->top()->creatFolder("Alfredo");
	path->top()->creatFolder("KindaCringe");
	path->top()->creatFolder("AAAAAA 4");
	path->top()->creatFolder("Dossier 5");
	path->top()->creatFolder("Dossier 6");
	path->top()->creatFolder("FOLDERSS");
	path->top()->creatFolder("Dossier 8");
	path->top()->createNote("Note 5");
	path->top()->createNote("Note 2");
	path->top()->createNote("Note 6");
	path->top()->createNote("Note 4");
	path->top()->createNote("Note 1");
	path->top()->createNote("Note 3");
}

void onRefresh() {
	// TODO : Afficher le contenu du dossier actuel
	//Faire une boucle pour afficher tous les dossiers et notes selon la largeur de la fenaitre
	int x = 0, y = 0;
	string name;

	for (int i = 0; i < path->top()->getFolderCount(); i++) {
		if(x + Window::getIconWidth() >= Window::getWidth()) {
			y+=Window::getIconHeight();
			x=0;
		}

		name = path->top()->getFolder(i)->getFolderName();
		Window::drawIcon(FOLDER, x, y);
		Window::drawString(name, (Window::getIconWidth() - Window::getStringWidth(name))/2 + x, (Window::getIconHeight() + y) - 25);

		x+=Window::getIconWidth();
	}

	for (int j = 0; j < path->top()->getNoteCount(); j++) {
		if(x + Window::getIconWidth() >= Window::getWidth()) {
			y+=Window::getIconHeight();
			x=0;
		}

		name = path->top()->getNote(j)->getName();
		Window::drawIcon(NOTE, x, y);
		Window::drawString(name, (Window::getIconWidth() - Window::getStringWidth(name))/2 + x, (Window::getIconHeight() + y) - 25);

		x+=Window::getIconWidth();
	}
}

void onWindowClick(const int& x, const int& y, const bool& button, const bool& ctrl) {
	if (button) {
		// TODO : Click sur un dossier ou une note du dossier actuel
	}
	else {
		// TODO : Afficher le menu

		//string nom = Window::showTextField("Nom Actuel");

		//Window::showMenu(x, y, Menu::NEW_FOLDER | Menu::NEW_NOTE);

	}
}

void onMenuClick(const unsigned int& menuItem) {
	switch (menuItem) {
	case Menu::NEW_FOLDER:
		// TODO : Créer un nouveau dossier dans le dossier actuel
		Window::showTextField();
		break;

	case Menu::NEW_NOTE:
		// TODO : Créer une nouvelle note dans le dossier actuel
		Window::setTitle("Nouveau Titre");
		break;

	case Menu::RENAME:
		// TODO : Renommer le dossier ou la note
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