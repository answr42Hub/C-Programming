#include "Queue.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    Queue<int>* fileDynamique = new Queue<int>();

    fileDynamique->push(42);
    fileDynamique->push(42);
    fileDynamique->push(42);
    fileDynamique->push(42);
    fileDynamique->push(42);
    fileDynamique->push(560);
    

    
    
    cout << fileDynamique->front() << endl;
    cout << fileDynamique->back() << endl;

return 0;
}