#include <cstdlib>

template <typename T>
class ArrayQueue {
private:
    T* array;
    size_t arrayLength;
    size_t frontIndex;
    size_t count;

public:
    ArrayQueue(size_t length) {
        array = new T[length];
        arrayLength = length;
        count = frontIndex = 0;
    }

    ~ArrayQueue() {
        delete[] array;
    }

    void push(T data) {
        if(count < arrayLength)
            array[(frontIndex + count++) % arrayLength] = data;
    }

    void pop() {
        if(count){
            frontIndex = ++frontIndex % arrayLength;
            count--;
        }
    }

    T front() {
        return (count) ? array[frontIndex] : 0;
    }

    T back() {
        return (count) ? array[(frontIndex + count - 1) % arrayLength] : NULL;
    }
    
    size_t size() {
        return count;
    }
};