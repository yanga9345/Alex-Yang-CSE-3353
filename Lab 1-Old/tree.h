#ifndef TREE_H
#define TREE_H

#include <vector>

class Tree
{
private:

public:
    struct Node
    {
        int key;
        struct Node * left, * right;
    };

    /*
    //static struct Tree::Node * CreateNode(int id);
    //static struct Tree::Node * InsertNode(Tree::Node *, int id);
    static struct Node * CreateNode(int id);
    static struct Node * InsertNode(Tree::Node *, int id);
    static void CopySortedTree(Tree::Node *, std::vector<int> &, int &i);
    */
    struct Node * CreateNode(int id)
    {
        struct Tree::Node * node = new Tree::Node();
        node->key = id;
        node->left = 0;
        node->right = 0;

        return node;
    }

    struct Node * InsertNode(Tree::Node * node, int id)
    {
        if(node == 0)
        {
            return Tree::CreateNode(id);
        }
        if(id < node->key)
        {
            node->left = Tree::InsertNode(node->left, id);
        }
        else if(id > node->key)
        {
            node->right = Tree::InsertNode(node->right, id);
        }
        return node;
    }

    void CopySortedTree(Tree::Node * node, std::vector<int> &data, int &i)
    {
        if(node != 0)
        {
            Tree::CopySortedTree(node->left, data, i);
            data[i++] = node->key;
            Tree::CopySortedTree(node->right, data, i);
        }
    }

};

#endif // TREE_H
