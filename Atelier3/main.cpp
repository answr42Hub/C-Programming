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
  if(op == "(" || op == ")")
    return '0';
  if(op == "+" || op == "-")
    return '1';
  if(op == "/" || op == "*" || op == "%")
    return '2';
  return 0;
}

//Transformation d'une epression infixe a une expression postfixe
ArrayQueue<string>* infixToPostfix(ArrayQueue<string>* expression) {
  //Declaration et instantiation de la file postefix et instantiation de la file expression
  expression = new ArrayQueue<string>(25);
  ArrayQueue<string>* postfix;
  postfix = new ArrayQueue<string>(25);
  
  //Declaration et instantiation de la pile
  ArrayStack<string>* pileOp = new ArrayStack<string>(15);

  while(expression->size()) {
    if(!isOperator(expression->front())) {
      postfix->push(expression->front());
      expression->pop();
    }

    else {

      if(expression->front() == "(") {
        pileOp->push(expression->front());
        expression->pop();
      }

      else if(expression->front() == ")") {
        while(pileOp->top() != "(") {
          postfix->push(pileOp->top());
          pileOp->pop();
        }
        pileOp->pop();
        expression->pop();
      }

      while(pileOp->size() && getPriority(expression->front()) < getPriority(pileOp->top())){
        postfix->push(pileOp->top());
        pileOp->pop();
      
      }
      pileOp->push(expression->front());
      expression->pop();
    }
    
  }
  delete[] expression, pileOp;
  return postfix;
}

// Calcul du résultat d'un expression postfixe.
int postfixToResult(ArrayQueue<string>* expression) {
  
  int result, num1, num2;
  ArrayStack<string>* operandePile = new ArrayStack<string>(10);
  
  while(expression->size()) {

    if(!isOperator(expression->front())) {
      operandePile->push(expression->front());
      expression->pop();
    }

    else {
      switch (expression->front()[0]) {
        case '+':
          expression->pop();
          num2 = stoi(operandePile->top());
          operandePile->pop();
          num1 = stoi(operandePile->top());
          operandePile->pop();

          result = num1 + num2;
          operandePile->push(to_string(result));
          break;

        case '-':
          expression->pop();
          num2 = stoi(operandePile->top());
          operandePile->pop();
          num1 = stoi(operandePile->top());
          operandePile->pop();

          result = num1 - num2;
          operandePile->push(to_string(result));
          break;

        case '*':
          expression->pop();
          num2 = stoi(operandePile->top());
          operandePile->pop();
          num1 = stoi(operandePile->top());
          operandePile->pop();

          result = num1 * num2;
          operandePile->push(to_string(result));
          break;
    
        case '/':
          expression->pop();
          num2 = stoi(operandePile->top());
          operandePile->pop();
          num1 = stoi(operandePile->top());
          operandePile->pop();

          result = num1 / num2;
          operandePile->push(to_string(result));
          break;

        default:
          break;
      }
    }
    
  }

  delete[] expression;
  return result;
}

///\brief Fonction principale.
///\return Code de terminaison de programme.
int main() {
  // TODO : Déclaration et instanciation d'une file.
  ArrayQueue<string>* fileExpr = new ArrayQueue<string>(25);

  string expr = "42+(5*10-6)-9*4";
  string num = "";
  
  // TODO : Enfilement des opérandes et des opérateurs d'un expression.
  for(int i = 0; i < expr.length(); i++) {
    while(expr[i] >= 48 && expr[i] <= 57) {
      num += expr[i++];
    }
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
      default :
       cout << "The expression entered is not valid" << endl;
      break;
    }
    
  }
  while(fileExpr->size()) {
    cout << fileExpr->front();
    fileExpr->pop();
  }
  cout << endl;


  delete[] fileExpr;

  // TODO : Appel des fonction pour transformer l'expression et calculer le résultat.

  return 0;
}