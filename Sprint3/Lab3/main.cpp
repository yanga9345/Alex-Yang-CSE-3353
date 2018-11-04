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
int main()
{

    Search algo;
    algo.Load();
    algo.Select(0);
    algo.Execute();
    algo.Display();
    //algo.Save();
    algo.Stats();

    return 0;
}
