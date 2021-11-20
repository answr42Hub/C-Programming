#include <queue>
#include "DLNode.hpp"

using namespace std;

enum Traversal { Prefix, Infix, Postfix };

template <typename T>
class BSTree {
private:
    DLNode<T>* root;
    size_t count;

    void prefixTraversal(DLNode<T>* node, queue<T>* traversalQueue) {
        traversalQueue->push(node->data);
        if (node->left)
            prefixTraversal(node->left, traversalQueue);
        if(node->right)
            prefixTraversal(node->right, traversalQueue);
    }

    void infixTraversal(DLNode<T>* node, queue<T>* traversalQueue) {
        if (node->left)
            infixTraversal(node->left, traversalQueue);
        traversalQueue->push(node->data);
        if(node->right)
            infixTraversal(node->right, traversalQueue);
    }

    void postfixTraversal(DLNode<T>* node, queue<T>* traversalQueue) {
        if (node->left)
            postfixTraversal(node->left, traversalQueue);
        if(node->right)
            postfixTraversal(node->right, traversalQueue);
        traversalQueue->push(node->data);
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
                    if(runner->right)
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
        else {
            root = new DLNode<T>(data);
            count++;
        }
    }

    void remove() {
        DLNode<T>* parent = root;
        //Positionner le pointeur "parent"

        DLNode<T>* toDelete = root->right;
        //positionner le toDelete selon la disposition du parent

        if(!toDelete->left && !toDelete->right) {
            //Le noeud a retirer est une feuille
        }
        else if(toDelete->left && toDelete->right) {
            //Le noeud a retirer a deux enfants
        }
        else {
            //Le noeud a retirer a 1 enfant
        }
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

    queue<T>* traversal(Traversal type) {
        
        queue<T>* traversalQueue = new queue<T>();
        
        if(root) {
            switch (type) {
            case Traversal::Prefix:
                prefixTraversal(root, traversalQueue);
                break;
            case Traversal::Infix:
                infixTraversal(root, traversalQueue);
                break;
            case Traversal::Postfix:
                postfixTraversal(root, traversalQueue);
                break;
            }
        }
        return traversalQueue;
    }

};