#include "sort.h"


//Sort::algorithms
void Sort::Select(int id)
{
    activeAlgo = Sort::algorithms[id];
}

void Sort::Exe()
{
    //activeAlgo(Sort::intData);
}

void Sort::Load(vector<int> &dat)
{
    intData = dat;
}
