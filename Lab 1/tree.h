#ifndef TREE_H
#define TREE_H

#include <vector>

class Tree{
public:
    struct Node
    {
        int key;
        struct Node * left, * right;
    };

    static struct Tree::Node * CreateNode(int id);
    static struct Tree::Node * InsertNode(Tree::Node *, int id);
    static void CopySortedTree(Tree::Node *, std::vector<int> &, int &i);

};

#endif // TREE_H
