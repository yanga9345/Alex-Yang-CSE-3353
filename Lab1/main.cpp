#include <iostream>
#include <fstream>
#include "algorithm.h"
#include "bubble.h"
#include "insertion.h"
#include "merge.h"
#include "sort.h"
#include "sortalgo.h"
#include "tree.h"

using namespace std;

int main(int argc, char** argv)
{
    enum AlgorithmType
    {
        BUBBLE = 0,
        INSERTION = 1,
        MERGE = 2,
        LAST
    };
    //AlgorithmType algorithmtype;

    vector<int> numList;
    numList.push_back(1);
    Sort algo;
    //SortAlgo sa;

    algo.Load(argv[1]);
    algo.Select(0);
    algo.Exe();
    //sa.Bubble(algo.intData);
    algo.Display();
    /*
    for(int i = 0; i < algo.Last; i++)
    {

        //ifstream inFile(argv[i]);
        //Sort algo(inFile);
        //algo.Load(int(BUBBLE));
        //algo.Display();
        //algo.Select();

    }
    */

    //std::vector<void(*)(std::vector<int>&)> Sort::algorithms;

    //load
    //Sort::algorithms.push_back(&);

    return 0;
}


