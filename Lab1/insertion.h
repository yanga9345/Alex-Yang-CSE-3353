#ifndef INSERTION_H
#define INSERTION_H
#include "sortalgo.h"

class Insertion
{
private:
    std::string name;
public:
    std::string getName();
    template <typename T>
    static void InsertionSort(std::vector<T> &data)
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
    }
};

#endif // INSERTION_H
