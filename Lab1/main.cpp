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
#include "tree.h"
#include "filegenerator.h"

using namespace std;

//runs the whole program
int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    FileGenerator f;
    f.Run();

    vector<string> filenames;

    filenames = f.getFileNames();

    Sort algo;

    for(string f: filenames)
    {
        algo.Load((char*)f.c_str());
        for(int i = 0; i < 3; i++)
        {
            algo.Select(i);
            algo.Execute();
            //algo.Display();
            algo.Stats();
            algo.Save();
        }
    }
    //algo.Save();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    cout << "Total Time Elapsed: " << setprecision(3) <<
            elapsed.count() << " seconds " << endl;
    return 0;
}
