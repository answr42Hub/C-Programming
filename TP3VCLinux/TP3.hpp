#include <stack>
#include <queue>
//#include "BSTree.hpp"
//#include "AVLTree"
#include "Folder.hpp"

using namespace std;

Folder* root;
stack<Folder*>* path;
//AVLTree<int>* selections;

int getIndex(const int& x, const int& y) {
	// TODO : Retourner l'indice de l'élément clické
	return -1;
}

void onInit() {
	// TODO : Initialisations
}

void onRefresh() {
	Window::drawIcon(Icon::FOLDER, 0, 0);
	Window::drawString("DOSSIER", 0, Window::getIconHeight());
	Window::drawIcon(Icon::NOTE, Window::getIconWidth(), 0);
	Window::drawIcon(Icon::HUFFMAN, Window::getIconWidth()*2, 0);
	
	// TODO : Afficher le contenu du dossier actuel
}

void onWindowClick(const int& x, const int& y, const bool& button, const bool& ctrl) {
	if (button) {
		// TODO : Click sur un dossier ou une note du dossier actuel
	}
	else {
		// TODO : Afficher le menu
		Window::showMenu(x, y, Menu::NEW_FOLDER | Menu::NEW_NOTE);
	}
}

void onMenuClick(const unsigned int& menuItem) {
	switch (menuItem) {
	case Menu::NEW_FOLDER:
		// TODO : Créer un nouveau dossier dans le dossier actuel
		break;

	case Menu::NEW_NOTE:
		// TODO : Créer une nouvelle note dans le dossier actuel
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