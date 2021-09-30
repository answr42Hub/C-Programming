#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"

/*

	[CHOSES A RETENIR POUR LA MATIERE]

	int entier;
	entier = 42;
	printf("Valeur : %i, Adresse : %p\n", entier, &entier);

	//->Declaration :

	int* pEntier;//Declaration d'un pointeur avec "*" a l'avant du type

	//->Indirection :

	pEntier = malloc(sizeof(int));//stock une adresse libre dans le pointeur pEntier avec le bon nombre d'octet
	*pEntier = 404;//stock la valeur 404 a l'adresse stockee dans pEntier, quand "*" est a l'avant de la variable pointeur

	printf("Valeur : %i, Adresse : %p\n", *pEntier, pEntier);

	//->Liberation :

	free(pEntier);

	//->Exemple de reelle utilite de sizeof pour malloc :

	ArrayStack* pPile;

	pPile = malloc(sizeof(ArrayStack));

	//->Dereferencement :

	int entier = 404;
	int* pEntier = malloc(4);
	pEntier = &entier;
	*pEntier = 666;
	printf("%i", entier);

	//Au terminal : 
	
	//666

	//->Pointeur de structure :

	struct Position {
		int x;
		int y;
	};

	struct Position pos;
	struct Position pPos = malloc(sizeof(Position));

	pos.x = 1;
	pos.y = 2;

	  pPos -> x=3;
	  pPos -> y=4;
		OU			} meme chose
	(*pPos).x = 3;
	(*pPos).y = 4;

	//->Tableau

	//char tabEntier[2]; 
	char* tabEntier;
	tabEntier = malloc(2);

	//tabEntier[0] = 42;
	*tabEntier = 42;
	//tabEntier[1] = 404;
	*(tabEntier+2) = 404;

*/


int main() {

	struct ArrayStack stackA;
	create(&stackA, 5);
	struct ArrayStack stackB;
	create(&stackB, 10);

	push(&stackA, 42);
	printf("PileA -> Dessus : %i, Compte : %i\n", top(&stackA), size(&stackA));

	push(&stackB, 404);
	printf("PileB -> Dessus : %i, Compte : %i\n", top(&stackB), size(&stackB));

	destroy(&stackA);
	destroy(&stackB);
	
	return 0;

}


