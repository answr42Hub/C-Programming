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
	void createFolder(string name) {
		folders.push_back(new Folder(name));
		quickSortFolders(0, folders.size()-1);
	}
	//Creation d'une note
	void createNote(string name) {
		notes.push_back(new Note(name));
		quickSortNotes(0, notes.size()-1);
	}
	//Obtenir un dossier
	Folder* getFolder(size_t index) {
		return folders[index];
	}
	//Obtenir le nom d'un dossier
	string getFolderName() {
		return name;
	}
	//Changer le nom du dossier
	void setFolderName(string newName) {
		name = newName;
	}
	//Obtenir une note
	Note* getNote(size_t index) {
		return notes[index];
	}
	//Obtenir le nombre de sous-dossiers
	size_t getFolderCount() {
		return folders.size();
	}
	//Obtenir le nombre de notes
	size_t getNoteCount() {
		return notes.size();
	}
	//Trier les vecteurs Folder*
	void quickSortFolders(int iMin, int iMax) {
		int g = iMin, p = iMin, d = iMax;
  
  		while (g != d) {
    		if (folders[g]->getFolderName() > folders[d]->getFolderName()) {
      			swap(folders[g], folders[d]);
      		p = g + d - p;
    	}

    	(p == g) ? d-- : g++;    
  		}
  
  		if (iMin < p - 1) quickSortFolders(iMin, p - 1);
  		if (iMax > p + 1) quickSortFolders(p + 1, iMax);  
	}

	//Trier les vecteurs Note*
	void quickSortNotes(int iMin, int iMax) {
		int g = iMin, p = iMin, d = iMax;
  
  		while (g != d) {
    		if (notes[g]->getName() > notes[d]->getName()) {
      			swap(notes[g], notes[d]);
      		p = g + d - p;
    	}

    	(p == g) ? d-- : g++;    
  		}
  
  		if (iMin < p - 1) quickSortNotes(iMin, p - 1);
  		if (iMax > p + 1) quickSortNotes(p + 1, iMax);  
	}


};
