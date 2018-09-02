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

int main()
{
    cout << "Hello World!" << endl;

    enum AlgorithmType
    {
        BUBBLE = 0,
        INSERTION = 1,
        MERGE = 2,
        LAST
    };

    for(int i = 0; i < Algorithm::Sort::Last; i++)
    {

        ifstream inFile(argv[i]);
        Sort algo(inFile);
        algo.Load();
        //algo.Display();
        //algo.Select();

    }
    return 0;
}
/*

std::vector<void(*)(std::vector<int>&)> Sort::algorithms;
std

//load
Sort::algorithms.push_back(&)

*/
