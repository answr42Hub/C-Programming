//ArrayStack.h
#include <stdio.h>


struct ArrayStack {
	int *pile;
	int size;
	int pileIndex;
};


// Allocation de la pile
void create(struct ArrayStack* stack, int size) {
	stack->pile = malloc(size*sizeof(int));
	stack->size = size;
	stack->pileIndex = 0;
}

//Liberation de la pile
void destroy(struct ArrayStack* stack) {
	free(stack->pile);
}

//Empiler la donnee sur la pile
void push(struct ArrayStack* stack, int data) {
	if(stack->pileIndex < stack->size) {
		stack->pile[stack->pileIndex++] = data;
	}
	
}

// Depiler la donnee au dessus de la pile
void pop(struct ArrayStack* stack) {
	if(stack->pileIndex) 
		stack->pileIndex--;
} 

int top(struct ArrayStack* stack) {
	return (stack->pileIndex) ? stack->pile[stack->pileIndex-1] : 0;
}

int size(struct ArrayStack* stack) {
	return stack->pileIndex;
}