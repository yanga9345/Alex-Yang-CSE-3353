#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <vector>

class Algorithm
{
private:
    std::vector<int> intData;
public:
    std::vector<int> algorithmList;
    int Last;
    Algorithm();
    void Load(std::vector<int> &dat)
    {
        intData = dat;
    }
    void Exe();
    void Save();
    void Stats();
    void Select();
};

#endif // ALGORITHM_H
