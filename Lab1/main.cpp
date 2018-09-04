#include <iostream>
#include <fstream>
#include "algorithm.h"
#include "bubble.cpp"
#include "insertion.cpp"
#include "merge.cpp"
#include "sort.h"
#include "sortalgo.h"
#include "tree.h"

using namespace std;

int main(int argc, char** argv)
{
    cout << "Hello World!" << endl;

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

    //ifstream inFile(argv[2]);

    algo.Load(argv[1]);
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


