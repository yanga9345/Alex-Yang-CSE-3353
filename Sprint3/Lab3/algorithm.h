#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <string>
#include <vector>

//Algorithm base class
class Algorithm
{
public:
    //virtual functions to be defined in Sort
    virtual void Load(char*){}
    virtual void Select(int id) = 0;
    virtual void Execute() = 0;
    virtual void Display(){}
    virtual void Stats(){}
    virtual void Save(){}
};

#endif // ALGORITHM_H
