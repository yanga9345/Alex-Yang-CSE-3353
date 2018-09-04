#ifndef BUBBLE_H
#define BUBBLE_H
#include <string>
#include <vector>

class Bubble
{
private:
    std::string name;
public:
    Bubble();
    std::string getName();
    template<typename T>
    void Sort(std::vector<T> &data)
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
    }
};

#endif // BUBBLE_H
