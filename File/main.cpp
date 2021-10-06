#include <iostream>
#include "ArrayQueue.hpp"

using namespace std;

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

    cout << "front : " << file.front() << ", back : " << file.back() << ", Compte : " << file.size() << endl;

    return 0;
}