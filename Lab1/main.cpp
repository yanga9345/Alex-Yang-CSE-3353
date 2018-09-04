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

    Sort algo;

    for(int i = 0; i < 3; i++)
    {
        algo.Load(argv[1]);
        algo.Select(i);
        algo.Execute();
        algo.Display();
        //algo.Stats();
        //algo.Save();
    }

    return 0;
}


