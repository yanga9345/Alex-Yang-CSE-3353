#ifndef SORTALGO_H
#define SORTALGO_H
#include <vector>
#include <iostream>
#include "tree.h"

using namespace std;

//templated SortAlgo class containing all the algorithms (no .cpp)
class SortAlgo
{
public:
    SortAlgo();

    template<typename T>
    void BinaryTree(vector<T> &data)
    {
        SortAlgo::BinaryTreeSort(data, data.size());
    }

    template<typename T>
    void BinaryTreeSort(vector<T> &data, int index)
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

    //templated Bubble Sort Function
    template<typename T>
    static string BubbleSort(vector<T> &data)
    {
        T i, j, temp;
        int size = data.size();
        for (i = 0; i < size-1; i++)
            for (j = 0; j < size-i-1; j++)
                if (data[j] > data[j+1])
                {
                    temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                }
        return "Bubble Sort";
    }

    //templated Insertion Sort Function
    template<typename T>
    static string InsertionSort(vector<T> &data)
    {
        T key;
        int i, j, size = data.size();
        for (i = 1; i < size; i++)
        {
            key = data[i];
            j = i-1;

            while (j >= 0 && data[j] > key)
            {
                data[j+1] = data[j];
                j = j-1;
            }

            data[j+1] = key;
        }
        return "Insertion Sort";
    }

    //templated Merge Sort Function
    template<typename T>
    static string MergeSort(vector<T> &data)
    {
        recursiveMerge(data, 0, data.size() - 1);
        return "Merge Sort";
    }

    //Merge method for Merge Sort
    template<typename T>
    static void Merge(vector<T> &data, int left, int right, int middle)
    {
        int i, j, k;
        int temp1size = middle - left + 1;
        int temp2size = right - middle;

        //temp vectors
        vector<T> temp1 = {};
        vector<T> temp2 = {};

        //splits data into the two temp vectors
        for (i = 0; i < temp1size; i++)
            temp1.push_back(data[left + i]);
        for (j = 0; j < temp2size; j++)
            temp2.push_back(data[middle + 1 + j]);

        /*merges the temp vectors into one vector*/

        //starting index of first vector
        i = 0;
        //starting index of second vector
        j = 0;
        //starting index of merged vector
        k = left;

        while (i < temp1size && j < temp2size)
        {
            if (temp1[i] <= temp2[j])
            {
                data[k] = temp1[i];
                i++;
            }
            else
            {
                data[k] = temp2[j];
                j++;
            }
            k++;
        }

        //Copies any elements left in the temp1 vector
        while (i < temp1size)
        {
            data[k] = temp1[i];
            i++;
            k++;
        }

        //Copies any elements left in the temp2 vector
        while (j < temp2size)
        {
            data[k] = temp2[j];
            j++;
            k++;
        }
    }

    //recursively merges left and right subarrays
    template<typename T>
    static void recursiveMerge(vector<T> &data, int left, int right)
    {
        if (left < right)
        {
            //int middle = left + (right - left) / 2;
            int middle = (left + right)/2;

            //sorts both halves of the vector
            recursiveMerge(data, left, middle);
            recursiveMerge(data, middle + 1, right);

            //merges 2 subvectors
            Merge(data, left, right, middle);
        }
    }

};

#endif // SORTALGO_H
