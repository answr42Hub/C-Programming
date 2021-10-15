#include <string>
#include <iostream>
#include "ArrayStack.hpp"
#include "ArrayQueue.hpp"

using namespace std;

///\brief Déterminer s'il s'agit d'un opérateur.
///\param term Terme.
///\return S'il s'agit d'un opérateur.
bool isOperator(string term) {
  // TODO : Implémentation ...
}

///\brief Obtention de la priorité d'un opérateur.
///\param op Opérateur.
///\return Priorité de l'opérateur.
unsigned char getPriority(string op) {
  // TODO : Implémentation ...
}

///\brief Transformation d'une expression infixe en expression postfixe.
///\param expression Expression infixe.
///\return Expression postfixe.
ArrayQueue<string>* infixToPostfix(ArrayQueue<string>* expression) {
  // TODO : Implémentation ...
}

///\brief Calcul du résultat d'un expression postfixe.
///\param expression Expression postfixe.
///\return Résultat de l'expression.
int postfixToResult(ArrayQueue<string>* expression) {
  // TODO: Implémentation ...
}

///\brief Fonction principale.
///\return Code de terminaison de programme.
int main() {
  // TODO : Déclaration et instanciation d'une file.
  ArrayQueue<string> fileExpr(25);

  string expr = "2+(5*10-6)-69*2";
  string num = "";

  // TODO : Enfilement des opérandes et des opérateurs d'un expression.
  for(int i = 0; i < expr.length(); i++) {
    if(expr[i] >= 48 && expr[i] <= 57) {
      num += expr[i];
    }
    else {
      fileExpr.push(num);
      num = "";
      fileExpr.push(to_string(expr[i]));
    }
  }

  cout << fileExpr.front() << endl;
  cout << fileExpr.back() << endl;

  // TODO : Appel des fonction pour transformer l'expression et calculer le résultat.

  return 0;
}
/*
int main(int argc, char** argv) {
  ArrayQueue<string> fileLue(25);

  string infix = argv[1];

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

*/