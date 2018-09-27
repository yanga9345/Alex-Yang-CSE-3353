#ifndef SEARCHALGO_H
#define SEARCHALGO_H
#include <vector>
#include <iostream>

using namespace std;
//the reason my static sort algorithms return strings is because I want
//the names of the sorting method to be used in Sort (sortName)

//templated SortAlgo class containing all the algorithms (no .cpp)
#include <iostream>
#include <list>
#include <graph.h>

class SearchAlgo
{
public:
    SearchAlgo();

//    static string DFSIterative(int source, int dest)
//    {

//        return "DFS Iterative";
//    }


//    void DFSUtil(int v, bool visited[])
//    {

//    }

//    // The function to do DFS traversal. It uses recursive DFSUtil()
//    static string DFSRecursive(int source, int dest)
//    {
//        return "DFS Recursive";
//    }

//    static string BFSIterative(int source, int dest)
//    {
//        return "BFS Iterative";
//    }

//    static string BFSRecursive(int source, int dest)
//    {
//        return "BFS Recursive";
//    }

//    static string Dijkstra(int source, int dest)
//    {
//        return "Dijkstra";
//    }

//    static string AStar(int source, int dest)
//    {
//        return "A*";
//    }
    /**
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

        //temp arrays
        T temp1[temp1size];
        T temp2[temp2size];

        //splits data into the two temp arrays
        for (i = 0; i < temp1size; i++)
            temp1[i] = data[left + i];
        for (j = 0; j < temp2size; j++)
            temp2[j] = data[middle + 1 + j];

        //merges the temp arrays into one array

        //starting index of first array
        i = 0;
        //starting index of second array
        j = 0;
        //starting index of merged array
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

        //Copies any elements left in the temp1 array
        while (i < temp1size)
        {
            data[k] = temp1[i];
            i++;
            k++;
        }

        //Copies any elements left in the temp2 array
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
            int middle = (left + right)/2;

            //sorts both halves of the vector
            recursiveMerge(data, left, middle);
            recursiveMerge(data, middle + 1, right);

            //merges 2 subvectors
            Merge(data, left, right, middle);
        }
    }
    **/

};

#endif // SEATCHALGO_H
