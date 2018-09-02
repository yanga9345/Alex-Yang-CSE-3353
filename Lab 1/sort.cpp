#include "sort.h"


Sort::Sort(vector<int> &dat)
{
    intData = dat;
}
//Sort::algorithms
void Sort::Select(int id)
{
    activeAlgo = Sort::algorithms[id];
}

void Sort::Execute()
{
    activeAlgo(Sort::intData);
}
