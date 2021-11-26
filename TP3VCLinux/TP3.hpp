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

	path->top()->creatFolder("Dossier 1");
	path->top()->creatFolder("Dossier 2");
	path->top()->creatFolder("Dossier 3");
	path->top()->creatFolder("Dossier 4");
	path->top()->createNote("Note 1");
	path->top()->createNote("Note 2");
	path->top()->createNote("Note 3");
	
}

void onRefresh() {
	// TODO : Afficher le contenu du dossier actuel
	//Faire une boucle pour afficher tous les dossiers et notes selon la largeur de la fenaitre
	int x = 0, y = 0;
	string name;

	for(int i = 0; i < path->top()->getFolderCount(); i++) {

	}
	for(int y = 0; y < path->top()->getNoteCount(); y++) {

	}
	Window::drawIcon(FOLDER, 0, 0);
	Window::drawString(path->top()->getFolder(0)->getFolderName(), ((Window::getIconWidth()) - (Window::getStringWidth(path->top()->getFolder(0)->getFolderName())))/2, Window::getIconHeight()-25);
}

void onWindowClick(const int& x, const int& y, const bool& button, const bool& ctrl) {
	if (button) {
		// TODO : Click sur un dossier ou une note du dossier actuel
	}
	else {
		// TODO : Afficher le menu

		string nom = Window::showTextField("Nom Actuel");

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