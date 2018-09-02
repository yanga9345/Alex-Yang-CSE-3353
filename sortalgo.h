#ifndef SORTALGO_H
#define SORTALGO_H

using namespace std;

class SortAlgo
{
public:
    //template<typeName T>
    //static void Bubble(vector<T> &data);

    //template<typeName T>
    //static void BubbleSort(vector<T> &data, int index);

    template<typeName T>
    void SortAlgo::BinaryTree(vector<T> &data)
    {
        SortAlgo::BinaryTreeSort(data, data.size());
    }

    template<typeName T>
    void SortAlgo::BinaryTreeSort(vector<T> &data, int index)
    {
        struct Tree::Node * root = 0;
        root = Tree::InsertNode(root, data[0]);

        for(int i = 1; i < index; i++)
        {
            Tree::InsertNode(root, data[i]);
        }

        int i = 0;
        Tree::CopySortedTree(root, data, i);
    }
};

#endif // SORTALGO_H
