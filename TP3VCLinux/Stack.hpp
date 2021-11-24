#pragma once
#include "SLNode.hpp"
#include <cstdlib>
#include <type_traits>

template <typename T>
class Stack {

private:
SLNode<T>* first;
size_t count;

public:

    Stack() {
        first = nullptr;
        count = 0;
    }

    ~Stack() {
        while(count) {
            pop();
        }
    }

    void push(T data) {
        first = new SLNode<T>(data, first);
        count++;
    }

    void pop() {
        if(first) {
            SLNode<T>* toDelete = first;
            first = first->next;
            delete toDelete;
            
            count--;
        }
    }

    T top() {
        return (first) ? first->data : NULL;
    }

    size_t size() {
        return count;
    }

};