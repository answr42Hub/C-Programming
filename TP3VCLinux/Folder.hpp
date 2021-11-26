#include <vector>

#include "Note.hpp"

using namespace std;

class Folder {
private:
	string name;
	vector<Folder*> folders;
	vector<Note*> notes;

public:
	// TODO : Implémentation des méthodes nécessaires
	Folder(string name) {
		this->name = name;
	}
	//Creation d'un dossier
	void creatFolder(string name) {
		folders.push_back(new Folder(name));
	}
	//Creation d'une note
	void createNote(string name) {
		notes.push_back(new Note(name));
	}
	//Obtenir un dossier
	Folder* getFolder(size_t index) {
		return folders[index];
	}
	//Obtenir le nom d'un dossier
	string getFolderName() {
		return name;
	}
	//Obtenir une note
	Note* getNote(size_t index) {
		return notes[index];
	}
};
