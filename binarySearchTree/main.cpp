#include "BSTree.hpp"
#include <iostream>

using namespace std;

int main() {
    BSTree<int> arbre;
    queue<int>* traversal;
    
    arbre.add(42);
    arbre.add(404);
    arbre.add(666);
    arbre.add(32);
    arbre.add(69);
    arbre.add(23);
    arbre.add(11);
    arbre.add(12);
    arbre.add(29);
    arbre.add(42);

    //Parcours Prefix
    cout << "Parcours prefix : ";
    traversal = arbre.traversal(Traversal::Prefix);
    while(traversal->size()) {
        cout << traversal->front() << " ";
        traversal->pop();
    }
    delete traversal;
    cout << endl;

    //Parcours Infix
    cout << "Parcours infix : ";
    traversal = arbre.traversal(Traversal::Infix);
    while(traversal->size()) {
        cout << traversal->front() << " ";
        traversal->pop();
    }
    delete traversal;
    cout << endl;

    //Parcours Postfix
    cout << "Parcours Postfix : ";
    traversal = arbre.traversal(Traversal::Postfix);
    while(traversal->size()) {
        cout << traversal->front() << " ";
        traversal->pop();
    }
    delete traversal;
    cout << endl;

    return 0;
}