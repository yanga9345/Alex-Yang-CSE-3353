#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <string>
#include <vector>

//Algorithm base class
class Algorithm
{
public:
    //virtual functions to be defined in SearchAlgo
    virtual void Load() = 0;
    virtual void Select(int id) = 0;
    virtual void Execute() = 0;
    virtual void Display() = 0;
    virtual void Stats() = 0;
    virtual void Save() = 0;
};

#endif // ALGORITHM_H
