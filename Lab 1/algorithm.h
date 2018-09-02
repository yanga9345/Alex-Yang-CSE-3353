#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <vector>

class Algorithm
{
private:
    std::vector<int> intData;
public:
    Algorithm();
    Algorithm(std::vector<int> &);
    void Load();
    void Exe();
    void Save();
    void Stats();
    void Select();
};

#endif // ALGORITHM_H
