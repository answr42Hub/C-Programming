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
	//Obtenir le contenu du fichier
	string getContent(){
		return content;
	}
};
