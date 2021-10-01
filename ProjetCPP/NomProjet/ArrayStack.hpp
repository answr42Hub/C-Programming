class ArrayStack {
private:
    int* array;
    int maxSize;
    int topIndex;

public:    
    //Constructeur
    ArrayStack(int maxSize) {
        array = new int[maxSize];
        this->maxSize = maxSize;
        topIndex = 0;
    }

    //Destructeur
    ~ArrayStack() {
        delete array;
    }

    //Empiler la donnee sur la pile
    void push(int data) {
        if(topIndex < maxSize) {
            array[topIndex++] = data;
        } 
    }

    // Depiler la donnee au dessus de la pile
    void pop() {
        if(topIndex) 
            topIndex--;
    } 

    int top() {
        return (topIndex) ? array[topIndex-1] : 0;
    }

    int size() {
        return maxSize;
    }
};
