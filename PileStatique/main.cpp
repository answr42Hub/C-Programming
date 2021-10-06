#include "ArrayStack.hpp"
#include <cstdio>

int main() {

	//ArrayStack pileA(5); // Instance de la class ArrayStack - Tout se fait automatiquement : l'allocation et la liberation

	//ArrayStack*pPileA = new ArrayStack(5); //Nous avons le contôle quand la mémoire sera libérée
	//delete pPileA; //Mémoire libérée

	ArrayStack<int> pileEntiers(5);
	ArrayStack<char> pileCaracteres(10);
	ArrayStack<double> pileReels(20);

	pileCaracteres.push('4');
	printf("Pile char -­ Dessus: %c, compte: %lu­\n", pileCaracteres.top(), pileCaracteres.size());

	return 0;
}