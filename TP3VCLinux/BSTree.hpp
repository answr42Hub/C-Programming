#include "Queue.hpp"
#include "DLNode.hpp"

using namespace std;

enum Traversal { Prefix, Infix, Postfix };

template <typename T>
class BSTree {
private:
    DLNode<T>* root;
    size_t count;

    void prefixTraversal(DLNode<T>* node, Queue<T>* traversalQueue) {
        traversalQueue->push(node->data);
        if(node->left)
            prefixTraversal(node->left, traversalQueue);
        if(node->right)
            prefixTraversal(node->right, traversalQueue);
    }

    void infixTraversal(DLNode<T>* node, Queue<T>* traversalQueue) {
        if(node->right)
            infixTraversal(node->right, traversalQueue);
        traversalQueue->push(node->data);
        if(node->left)
            infixTraversal(node->left, traversalQueue);
    }

    void postfixTraversal(DLNode<T>* node, Queue<T>* traversalQueue) {
        if(node->left)
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

    void remove(T data) {
        if(root && count > 1) {
            DLNode<T>* parent = nullptr;
            DLNode<T>* toDelete = nullptr;

            if(root->data == data)
                toDelete = root;
            else
                parent = root;

            //Trouver le toDelete
            while(!toDelete) {
                if(data > parent->data){
                    if(parent->right){
                        if(parent->right->data == data) 
                            toDelete = parent->right;
                        else
                            parent = parent->right;
                    } 
                    else {
                        return;
                    }
                }
                else {
                    if(parent->left) {
                        if(parent->left->data == data) 
                            toDelete = parent->left;
                        else
                            parent = parent->left;
                    } 
                    else {
                        return;
                    }
                }
            }
            
            //Le noeud a retirer est une feuille
            if(!toDelete->left && !toDelete->right) {
                if(parent->left == toDelete)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
                
                delete toDelete;
                
                count--;
            }

            //Le noeud a retirer a deux enfants
            else if(toDelete->left && toDelete->right) {
                T temp;
                if(toDelete->left){
                    DLNode<T>* largest = toDelete->left;
                    //Trouver la plus grande donnée du sous-arbre de gauche, du noeud à retirer.
                    while(largest->right){
                        largest = largest->right;
                    }
                    temp = largest->data;

                    remove(largest->data);
                }
                else {
                    temp = toDelete->left->data;

                    remove(toDelete->left->data);
                }
                
                toDelete->data = temp;
                count--;
            }
            //Le noeud a retirer a un enfant
            else {
                if(parent)  {
                    if(parent->left == toDelete){
                        if(toDelete->left)
                            parent->left = toDelete->left;
                        else
                            parent->left = toDelete->right;
                    }
                    else {
                        if(toDelete->left)
                            parent->right = toDelete->left;
                        else
                            parent->right = toDelete->right;
                    }
                }
                else {
                    if(toDelete->left)
                        root = toDelete->left;
                    else
                        root = toDelete->right;
                }

                delete toDelete;
                count--;
            }
        }
        else {
            
            delete root;
            root = nullptr;
            count--;
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
                else {
                    return true;
                }
            }
        }
        return false;
    }

    Queue<T>* traversal(Traversal type) {
        
        Queue<T>* traversalQueue = new Queue<T>();
        
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

    void clear() {
        while(count) {
            remove(root->data);
        }
    }

    size_t size() {
        return count;
    }

};