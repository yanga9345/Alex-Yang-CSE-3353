#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <string>
#include <vector>

//Algorithm base class
class Algorithm
{
public:
    Algorithm(){}
    //pure virtual functions to be defined in Sort
    virtual void Load(char*) = 0;
    virtual void Select(int id) = 0;
    virtual void Execute() = 0;
    virtual void Display() = 0;
    virtual void Stats() = 0;
    virtual void Save() = 0;

    //Prototype
    virtual Algorithm * Clone() = 0;

    Algorithm(const Algorithm & alg);
};

#endif // ALGORITHM_H
