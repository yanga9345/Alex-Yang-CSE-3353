/*
 * Alex Yang
 * Professor Clark
 * CSE 3353
 * September 27th, 2018
 *
 * Lab 2:
 *
 *
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
    Graph g;
    if(argc == 2)
    {

    }
    else if(argc == 3)
    {
        std::cout << "Hello World. " << endl;
        Search algo;
        algo.Load(argv);
        //algo.Select(0);
        //algo.Execute();
    }
    else
        cout << "Error. Invalid number of command line arguments." << endl;

    /**
    //keeps track of total program run time
    auto start = std::chrono::high_resolution_clock::now();

    //creates a FileGenerator object which creates all the initial data sets
    FileGenerator f;
    f.Run();

    //instantiates a vector of filenames to be used when running all the sorts
    vector<string> filenames = f.getFileNames();

    Algorithm algo;

    for(string f: filenames)
    {
        cout << endl;
        algo.Load((char*)f.c_str());
        for(int i = 0; i < 3; i++)
        {
            algo.Select(i);
            algo.Execute();
            //algo.Display(); //uncomment this to print the sorted numbers
            algo.Stats();
            algo.Save();
        }
    }

    //displays total program run time
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "Total Time Elapsed: " << setprecision(3) <<
            elapsed.count() << " seconds " << endl;

    **/

    return 0;
}
