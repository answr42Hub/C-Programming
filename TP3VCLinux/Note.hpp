#include <string>

using namespace std;

class Note {
private:
	string name;
	string content;

public:
	// TODO : Impl�mentation des m�thodes n�cessaires
	Note(string name, string content = "") {
		this->name = name;
		this->content = content;
	}

	//Obtenir le nom du fichier
	string getName(){
		return name;
	}
	//Changer le nom 
	void setNoteName(string newName) {
		name = newName;
	}
	//Changer le nom 
	void setNoteContent(string newContent) {
		content = newContent;
	}
	//Obtenir le contenu du fichier
	string getContent(){
		return content;
	}
};
