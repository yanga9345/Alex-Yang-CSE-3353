#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <vector>

class Algorithm
{
private:
    //std::vector<int> intData;
public:
    //std::vector<int> algorithmList;
    //int Last;
    virtual void Load(char*) = 0;
    virtual void Select(int id) = 0;
    virtual void Exe() = 0;
    virtual void Display() = 0;
    virtual void Stats() = 0;
    virtual void Save() = 0;
};

#endif // ALGORITHM_H
