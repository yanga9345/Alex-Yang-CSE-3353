#ifndef AVLTREE_H
#define AVLTREE_H

#include <iomanip>
#include <iostream>
using namespace std;
template<typename t>

//altered avltree class from data structures
class AVLTree
{
    private:
        int nodeCount = 0;
        class AVLNode
        {
        public:
            t element;
            AVLNode* left;
            AVLNode* right;
            int height;
            AVLNode(t& data, AVLNode* lt, AVLNode* rt, int h=0):element(data),left(lt),right(rt),height(h){}
        };
        AVLNode* root;

    public:
        //returns the height at a given node
        int height(AVLNode* n){
            if(n==nullptr)
                return -1;
            else
                return n->height;
        }

        int max(int a, int b){
            if(a > b)
               return a;
            if(b > a)
               return b;

            return a;
        }

        void insert(t x){
             insert(x,root);
        }

        //searches the AVL tree for a given object and returns
        // a copy of the object
       t& search(t x)const{
           return (search(x,root))->element;
       }

       bool contains(t x)const{
           return contains(x,root);
       }

       //ONLY FOR USE WITH WORD OBJECTS
       void printWord(ofstream &outFile){
           printWord(root, outFile);
       }

       // clears the AVL tree
       void clear(){
           clear(root);
       }

    private:

        //searches the given subtree for a given value and returns
        // pointer to the node that contains it
        AVLNode* search(t x, AVLNode* node)const{
            if(node == nullptr || x == node->element)
                return node;
            else if(x < node->element)
                return search(x,node->left);
            else if(x > node->element)
                return search(x,node->right);
            else{};
        }

        // returns true or false if a value is
        // in a given subtree
        bool contains(t x, AVLNode* node)const{
            if(node == nullptr)
                return false;
            else if(x == node->element)
                return true;
            else if(x < node->element)
                return search(x,node->left);
            else if(x > node->element)
                return search(x,node->right);
            else{};
        }
        void insert(t x, AVLNode* &node){
            if(node==nullptr){
                node = new AVLNode(x,nullptr,nullptr);
            }
            else if(x < node->element){
                insert(x,node->left);
                if(height(node->left)-height(node->right)==2){
                    if(x < node->left->element)
                        rotatewithLeftChild(node); // case 1
                    else
                        doublewithLeftChild(node); // case 2
                }
            }else if(x > node->element){
                insert(x,node->right);
                if(height(node->right)-height(node->left) == 2){
                    if(node->right->element < x)
                        rotatewithRightChild(node); // case 4
                    else
                        doublewithRightChild(node); // case 3
                }
              }else{};
            node->height = max(height(node->left),height(node->right))+1;
        }

        //CASE 1 ROTATION
       void rotatewithLeftChild(AVLNode*& k2){

           AVLNode* k1 = k2->left;
           k2->left = k1->right;
           k1->right = k2;

           k2->height = max(height(k2->left),height(k2->right))+1;
           k1->height = max(height(k1->left),k2->height)+1;
           k2 = k1;
       }
        //CASE 4 rotation
       void rotatewithRightChild(AVLNode*& k2){

           AVLNode* k1 = k2->right;
           k2->right = k1->left;
           k1->left = k2;

           k2->height = max(height(k2->left),height(k2->right))+1;
           k1->height = max(height(k1->right),k2->height)+1;
           k2 = k1;
       }

       //CASE 2 ROTATION
       void doublewithLeftChild(AVLNode*& k3){

           rotatewithRightChild(k3->left);
           rotatewithLeftChild(k3);
       }

       //CASE 3 ROTATION
       void doublewithRightChild(AVLNode*& k3){

           rotatewithLeftChild(k3->right);
           rotatewithRightChild(k3);
       }

       void print(AVLNode* p, int indent=0)
       {
           cout<< p->data << "\n ";
           if(p != NULL) {
               if(p->left) postorder(p->left, indent+4);
               if(p->right) postorder(p->right, indent+4);
               if (indent) {
                   cout << setw(indent) << ' ';
               }
           }
       }
        //ONLY FOR USE WITH WORD OBJECTS
       void printWord(AVLNode* node, ofstream &outFile)
       {
            if (node == nullptr)
                 return;

            /* first recur on left child */
            printWord(node->left);

            /* then print the data of node */
            node->element.write(outFile);

            /* now recur on right child */
            printWord(node->right);
       }

       void clear(AVLNode* &node)
       {
         if(node != nullptr) {
            clear(node->left);
            clear(node->right);
            delete node;
         }
         node = nullptr;
       }
};

#endif // AVLTREE_H
