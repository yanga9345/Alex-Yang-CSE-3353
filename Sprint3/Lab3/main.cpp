/*
 * Alex Yang
 * Professor Clark
 * CSE 3353
 * November 6th, 2018
 *
 * Lab 3:
 */

#include <iostream>
#include <fstream>
#include "search.h"
#include "searchalgo.h"
#include "node.h"

using namespace std;

//runs the whole program
int main(int argc, char** argv)
{

    Search algo;
    algo.Load(argv);
    algo.Select(0);
    algo.Execute();
    algo.Display();
    //algo.Save();
    algo.Stats();

    return 0;
}
