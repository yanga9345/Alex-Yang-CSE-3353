/*
 * Alex Yang
 * Professor Clark
 * CSE 3353
 * September 27th, 2018
 *
 * Lab 2: My program just creates an adjacencyList and tries to
 * input all the relevant data
 */

#include <iostream>
#include <fstream>
#include "search.h"
#include "searchalgo.h"
#include "graph.h"
#include "source.h"

using namespace std;

//runs the whole program
int main(int argc, char** argv)
{
    if(argc == 2)
    {

    }
    else if(argc == 3)
    {
        Search algo;
        algo.Load(argv);
        algo.Select(0);
        algo.Execute();
        algo.Display();
        algo.Stats();
    }
    else
        cout << "Error. Invalid number of command line arguments." << endl;


    return 0;
}
