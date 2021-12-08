/*
1 - Le noeud N devient la nouvelle racine

2 - L'enfant de gauche (G) devient l<enfant de droite de l'encienne racine (A)

3 - L'ancienne racine (A) devient l'enfant de gauche de la nouvelle racine (N)
*/

template <typename T>
class TLNode {
public:
    T data;
    TLNode<T>* up,
             * left,
             *right;

    TLNode(T data, TLNode<T>* up = nullptr, TLNode<T>* left = nullptr, TLNode<T>* right = nullptr) {
        this->data=data;
        this->up=up;
        this->left=left;
        this->right;
    }
};

template <typename T>
class AVLTree {
private:
    TLNode<T> root;


    //Faire le constructeur

    void add(T data, TLNode<T>* node) {
        if(data > node->data) {
            if(node->right)
                add(data, node->right);
            else
                node->right = new TLNOde<T>(data, node);
        }
        else if(data < node->data) {
            if(node->right)
                add(data, node->left);
            else
                node->left = new TLNOde<T>(data, node);
        }
        // Clacul de l'indice d'equilibre
        /*
            indice d'équilibre = hauteur du sous-arbre de droite - hauteur du sous-arbre de gauche

            - (-2) : rotation a droite
            - (-1) : x
            - (0) : x
            - (1) : x
            - (2) : rotation a gauche

        */
    }
public :
    void add(T data) {
        if(root)
            add(data, root)
        else
            root = new TLNode(data);
    
    }
};