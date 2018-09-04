#include "tree.h"
/*
struct Tree::Node * Tree::CreateNode(int id)
{
    struct Tree::Node * node = new Tree::Node();
    node->key = id;
    node->left = 0;
    node->right = 0;

    return node;
}

struct Tree::Node * Tree::InsertNode(Tree::Node * node, int id)
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

void Tree::CopySortedTree(Tree::Node * node, std::vector<int> &data, int &i)
{
    if(node != 0)
    {
        Tree::CopySortedTree(node->left, data, i);
        data[i++] = node->key;
        Tree::CopySortedTree(node->right, data, i);
    }
}
*/

