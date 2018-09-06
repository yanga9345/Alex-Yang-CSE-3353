/*
 * Alex Yang
 * Professor Clark
 * CSE 3353
 * September 9th, 2018
 *
 * Lab 1:
 * This program will demonstrate the implementation of the strategy class design
 * pattern using the Bubble, Insertion, and Merge sorting algorithms.
 *
 */

#include <iostream>
#include <fstream>
#include "algorithm.h"
#include "sort.h"
#include "sortalgo.h"
#include "filegenerator.h"

using namespace std;

//runs the whole program
int main()
{
    //keeps track of total program run time
    auto start = std::chrono::high_resolution_clock::now();

    //creates a FileGenerator object which creates all the initial data sets
    FileGenerator f;
    f.Run();

    //instantiates a vector of filenames to be used when running all the sorts
    vector<string> filenames = f.getFileNames();

    //instantiates a Sort object which our program will use to
    //run all the Sorting Algorithms through
    Sort algo;

    //runs Bubble, Insertion, and Merge Sorts through each data set
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

    return 0;
}
