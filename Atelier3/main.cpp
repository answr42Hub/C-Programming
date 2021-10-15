#include <string>
#include <iostream>
#include "ArrayStack.hpp"
#include "ArrayQueue.hpp"

using namespace std;

// Déterminer s'il s'agit d'un opérateur.
// Terme.
// S'il s'agit d'un opérateur.
bool isOperator(string term) {
  if(term == "+" || term == "-" || term == "*" || term == "/" || term == "(" || term == ")" || term == "%") {
    return true;
  }
  
  return false;
}

///\brief Obtention de la priorité d'un opérateur.
///\param op Opérateur.
///\return Priorité de l'opérateur.
unsigned char getPriority(string op) {
  // TODO : Implémentation ...
  if(op == "(" || op == ")")
    return '0';
  if(op == "+" || op == "-")
    return '1';
  if(op == "/" || op == "*" || op == "%")
    return '2';
  return NULL;

}

///\brief Transformation d'une expression infixe en expression postfixe.
///\param expression Expression infixe.
///\return Expression postfixe.
ArrayQueue<string>* infixToPostfix(ArrayQueue<string>* expression) {
  expression = new ArrayQueue<string>(25);
  ArrayQueue<string>* postfix;
  postfix = new ArrayQueue<string>(25);
  
  ArrayStack<string> pileOp(15);

  while(expression->size() > 0) {
    if(!isOperator(expression->front())) {
      postfix->push(expression->front());
      expression->pop();
    }

    else if(pileOp.size() > 0){
      switch (expression->front()[0]) {
      case '-':
        if(getPriority(expression->front()))
        break;

      case '+':
        break;

      case '*':
        break;

      case '/':
        break;

      case '%':
        break;

      case ')':
      
      default:
        break;
      }
        
    }

    else 
      pileOp.push(expression->front());
    
  }

  return postfix;

  delete[] expression, postfix;
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

  string expr = "42+(5*10-6)-69*34";
  string num = "";
  
  // TODO : Enfilement des opérandes et des opérateurs d'un expression.
  for(int i = 0; i < expr.length()-1; i++) {
    while(expr[i] >= 48 && expr[i] <= 57) {
      num += expr[i++];
    }
    if(num != "") {
      fileExpr.push(num);
      num = "";
    }
    
    switch(expr[i]) {

      case '(' :
        fileExpr.push("(");

      break;

      case ')' :
        fileExpr.push(")");
        
      break;

      case '+' :
        fileExpr.push("+");
        
      break;

      case '-' :
        fileExpr.push("-");
        
      break;

      case '/' :
        fileExpr.push("/");
        
      break;

      case '*' :
        fileExpr.push("*");
        
      break;

      case '%' :
        fileExpr.push("%");
        
      break;

      default :
      break;
    }
      
  }

  // TODO : Appel des fonction pour transformer l'expression et calculer le résultat.

  return 0;
}