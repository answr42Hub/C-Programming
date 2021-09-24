#include <stdio.h>

#define MAX 10

int pile[MAX];
int pileIndex = 0;

void push(int entier) {
	if(pileIndex < MAX) {
		pile[pileIndex++] = entier;
	}
	else {
		printf("La pile est pleine\n");
	}
	
}

void pop() {
	if(pileIndex) 
		pileIndex--;
	else
		printf("La pile est vide\n");	
} 

int top() {
	return (pileIndex) ? pile[pileIndex-1] : NULL;
}

int size() {
	return pileIndex;
}