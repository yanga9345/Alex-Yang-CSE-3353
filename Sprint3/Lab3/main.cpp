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
#include "node.h"
//#include "graph.h"
//#include "source.h"

using namespace std;

//runs the whole program
int main(int argc, char** argv)
{

    //testGraph();
    if(argc == 3)
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

    vector<Node> vec;

//    ifstream inFile("positions.txt");

//    char * c_str = new char[20];
//    while(inFile.good())
//    {
//        inFile.getline(c_str, 20);
//        cout << c_str << endl;
//    }


    return 0;
}
