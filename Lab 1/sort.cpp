#include "sort.h"

/*
Sort::Sort()
{
    //Sort::algorithms
    void Sort::Select(int id)
    {
        activeAlgo = Sort::algorithms[id];
    }

    void Sort::Execute()
    {
        activeAlgo(Sort::intData);
    }
}
*/
//Sort::algorithms
void Sort::Select(int id)
{
    activeAlgo = Sort::algorithms[id];
}

void Sort::Execute()
{
    activeAlgo(Sort::intData);
}
