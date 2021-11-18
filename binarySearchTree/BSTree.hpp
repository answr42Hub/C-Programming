#include <queue>
#include "DLNode.hpp"

using namespace std;

template <typename T>
class BSTree {
private:
    DLNode<T>* root;
    size_t count;

    queue<T>* infixTraversal(DLNode<T>* node, queue<T>* traversalQueue) {
        if (node->left)
            infixTraversal(node->left);
        traversalQueue->push(node->data);
        if(node->right)
            infixTraversal(node->right, traversalQueue);
    }

public:
    BSTree() {
        root = nullptr;
        count = 0;
    }

    void add(T data) {
        if(root) {
            DLNode<T>* runner = root;
            while(runner) {
                if(data < runner->data) {
                    if(runner->left)
                        runner = runner->left;
                    else {
                        runner->left = new DLNode<T>(data);
                        runner = nullptr;
                        count++;
                    }
                }
                else if(data > runner->data) {
                    if(nunner->right)
                        runner = runner->right;
                    else {
                        runner->right = new DLNode<T>(data);
                        runner = nullptr;
                        count++;
                    }
                }
                else
                    runner = nullptr;
            }
        }
        else
            root = new DLNode<T>(data);
    }

    bool search(T data) {
        if(root) {
            DLNode<T>* runner = root;
            while(runner) {
                if(data < runner->data)
                    runner = runner->left;
                else if(data > runner->data) 
                    runner = runner->right;
                else
                    return true;
            }
            return false;
        }
    }

    queue<T> infixTraversal() {
        
        queue<T>* traversalQueue = new queue<T>();
        
        if(root)
            infixTraversal(root, traversalQueue);
        return traversalQueue;
    }

};