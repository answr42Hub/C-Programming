#include <string>
#include <iostream>
#include "ArrayQueue.hpp"
#include "ArrayStack.hpp"

using namespace std;

ArrayQueue<string>* infixToPostfix(ArrayQueue<string>* expressionQueue) {
    
}

int postfixToResult(ArrayQueue<string>* postfixQueue) {
  // TODO: Implémentation ...
}


int main(int argc, char** argv) {
  ArrayQueue<string> fileLue(25);

  string infix = argv[1];
  string num;

  for(int i = 0; i < infix.length(); i++) {
    if(infix[i] >= 48 && infix[i] <= 57) {
      num += infix[i];
    }
    else {
      fileLue.push(num);
      num="";
      fileLue.push(to_string(infix[i]));
    }
  }

  
  cout << fileLue.front() << endl;
  cout << fileLue.back() << endl;
    
  

    

  // TODO : Enfilement des opérandes et des opérateurs de l'expression infixe.

  // TODO : Appel des fonction pour transformer l'expression et calculer le résultat.

  return 0;
}