#include "SLNode.hpp"
#include <cstdlib>

template <typename T> class Queue {

private:
    SLNode<T>* first;
    SLNode<T>* last;
    size_t count;

public:
    Queue() {
        first = last = nullptr;
        count = 0;
    }

    ~Queue() {
        while(count) {
            pop();
        }
    }

    void push(T data) {
        if(!last)
            first = last = new SLNode<T>(data, nullptr);
        else 
            last = last->next = new SLNode<T>(data, nullptr);
         
        count++;
   }

    void pop() {
        if(first) {
            SLNode<T>* toDelete = first;
            first = first->next;
            delete toDelete;
            if(!first)
                last = nullptr;
            count--;
        }
    }

    T front() {
        return (first) ? first->data : NULL;
    }

    T back() {
        return (last) ? last->data : NULL;
    }

    size_t size() {
        /*autre moyen sans avoir besoin de count.
        size_t count = 0;
        SLNode<T>* runner = first;
        
        while(runner) {
            runner = runner->next;
            count++;
        }
        */
        return count;
    }


};