#include "ArrayQueue.hpp"
#include <stdio.h>

int main() {
    ArrayQueue<int> file(5);

    file.push(42);
    file.push(404);
    file.pop();//pop 42
    file.push(666);
    file.push(52);
    file.push(123);
    file.pop();//pop 404
    file.push(35);
    file.push(99);

    file.push(67);// ne push pas puisqu'il dépasse l'indexe

    printf("front : %i, back : %i, Compte : %i", file.front(), file.back(), file.size());
}