#include <string>
#include <iostream>
#include "ArrayStack.hpp"
#include "ArrayQueue.hpp"

using namespace std;

// Déterminer s'il s'agit d'un opérateur.
// Terme.
// S'il s'agit d'un opérateur.
bool isOperator(string term) {
  switch(term[0]) {

    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '(':
    case ')':
      return true;
      break;
  
  }

  return false;
}

// Obtention de la priorité d'un opérateur.
unsigned char getPriority(string op) {

  switch(op[0]) {
    case '(' :
    case ')' :
      return 0;
    case '+' :
    case '-' :
      return 1;
    case '*' :
    case '/' :
      return 2;
  }
  return 0;
}

//Transformation d'une epression infixe a une expression postfixe
ArrayQueue<string>* infixToPostfix(ArrayQueue<string>* expression) {

  ArrayQueue<string>* postfix = new ArrayQueue<string>(25);
  ArrayStack<string>* pileOp = new ArrayStack<string>(15);

  while(expression->size()) {
    if(!isOperator(expression->front())) {
      postfix->push(expression->front());
    }

    else if(expression->front() == "(") {
      pileOp->push(expression->front());
    }

    else {
      if(expression->front() == ")") {
        while(pileOp->top() != "(") {
          postfix->push(pileOp->top());
          pileOp->pop();
        }
        pileOp->pop();
      } 
      
      else {
        while(pileOp->size() && getPriority(expression->front()) <= getPriority(pileOp->top())){
          postfix->push(pileOp->top());
          pileOp->pop();
        }
        pileOp->push(expression->front());
      }
    }
    
    expression->pop();
  }

  while(pileOp->size()) {
    postfix->push(pileOp->top());
    pileOp->pop();
  }

  delete expression, pileOp;
  return postfix;
}

// Calcul du résultat d'un expression postfixe.
int postfixToResult(ArrayQueue<string>* expression) {
  
  int num1, num2;
  ArrayStack<int>* operandePile = new ArrayStack<int>(10);
  
  while(expression->size()) {

    if(!isOperator(expression->front())) {
      operandePile->push(stoi(expression->front()));
    }

    else {
      num2 = operandePile->top();
      operandePile->pop();
      num1 = operandePile->top();
      operandePile->pop();

      switch (expression->front()[0]) {
        case '+':
          operandePile->push(num1 + num2);
          break;

        case '-':
          operandePile->push(num1 - num2);
          break;

        case '*':
          operandePile->push(num1 * num2);
          break;
    
        case '/':
          operandePile->push(num1 / num2);
          break;

        default:
          break;
      }
    }
    expression->pop();
  }

  delete expression;
  return operandePile->top();
}

///\brief Fonction principale.
///\return Code de terminaison de programme.
int main(int argc, char **argv) {
  //Déclaration et instanciation d'une file.
  ArrayQueue<string>* fileExpr = new ArrayQueue<string>(25);
  ArrayQueue<string>* postfixExpr = new ArrayQueue<string>(25);;

  string expr = argv[1];
  string num = "";
  
  //Enfilement des opérandes et des opérateurs d'un expression.
  for(int i = 0; i < expr.length(); i++) {
    while(expr[i] >= 48 && expr[i] <= 57) 
      num += expr[i++];
    
    if(num != "") {
      fileExpr->push(num);
      num = "";
    }
    string s(1, expr[i]);
    switch(expr[i]) {
      case '(' :
      case ')' :
      case '+' :
      case '-' :
      case '/' :
      case '*' :
      case '%' :
        fileExpr->push(s);
        break;
    }
  }

  cout << "Infix : " << expr << endl;
  cout << "Postfix : ";
  fileExpr = infixToPostfix(fileExpr);
  
  while(fileExpr->size()) {
    cout << fileExpr->front();
    postfixExpr->push(fileExpr->front());
    fileExpr->pop();
  }
  
  cout << endl << "Evaluation : " << postfixToResult(postfixExpr) << endl;


  // TODO : Appel des fonction pour transformer l'expression et calculer le résultat.

  return 0;
}