#include "Deque.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;
int main() {
    
    Deque<int> myDeque;

    myDeque.push_front(42);
    myDeque.push_front(19);
    myDeque.push_front(420);
    myDeque.push_back(12);
    myDeque.push_back(404);
    myDeque.push_back(666);

    cout << myDeque.front() << endl;
    cout << myDeque.back() << endl;

    myDeque.pop_front();

    cout << myDeque.front() << endl;
    cout << myDeque.back() << endl;
    
    myDeque.pop_back();

    cout << myDeque.front() << endl;
    cout << myDeque.back() << endl;

    return 0;
}