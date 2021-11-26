#include <vector>

#include "Note.hpp"

using namespace std;

class Folder {
private:
	string name;
	vector<Folder*> folders;
	vector<Note*> notes;

public:
	// TODO : Impl�mentation des m�thodes n�cessaires
	Folder(string name) {
		this->name = name;
	}

	void creatFolder(string name) {
		folders.push_back(new Folder(name));
	}

};
