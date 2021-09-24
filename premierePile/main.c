#include <stdio.h>
#include "stack.h"

int main() {

	push(59);
	push(1);
	push(55);
	push(56);
	push(101);
	push(24);
	push(42);

	pop();
	pop();
	pop();
	pop();
	
	
	for(int i = pileIndex-1; i >= 0; i--){
		printf("0x0%d %d\n", i, pile[i]);
	}
	return 0;
}