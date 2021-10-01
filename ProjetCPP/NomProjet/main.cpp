#include "ArrayStack.hpp"

int main() {

	//ArrayStack pileA(5); // Instance de la class ArrayStack - Tout se fait automatiquement : l'allocation et la liberation

	//ArrayStack*pPileA = new ArrayStack(5); //Nous avons le contôle quand la mémoire sera libérée
	//delete pPileA; //Mémoire libérée

	ArrayStack<int> pile(5);

	return 0;
}