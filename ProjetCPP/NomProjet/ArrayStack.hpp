#include <cstdlib>

// Pile statique
template <typename T>
class ArrayStack {
private:
    T* array;
    size_t maxSize;
    size_t topIndex;

public:    
    //Constructeur
    ArrayStack(int maxSize) {
        array = new T[maxSize];
        this->maxSize = maxSize;
        topIndex = 0;
    }

    //Destructeur
    ~ArrayStack() {
        delete[] array;
    }

    //Empiler la donnee sur la pile
    void push(T data) {
        if(topIndex < maxSize) {
            array[topIndex++] = data;
        } 
    }

    // Depiler la donnee au dessus de la pile
    void pop() {
        if(topIndex) 
            topIndex--;
    } 

    T top() {
        return (topIndex) ? array[topIndex-1] : 0;
    }

    siz_t size() {
        return maxSize;
    }
};
