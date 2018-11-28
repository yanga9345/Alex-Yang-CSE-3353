/*
 * Alex Yang
 * Professor Clark
 * CSE 3353
 * November 6th, 2018
 *
 * Lab 3: Solves the Traveling Salesman Problem with Brute Force(Naive)
 *  and Dynamic Programming Methods
 */

#include <iostream>
#include <fstream>
#include "search.h"

using namespace std;

//runs algorithms for different graph sizes (4-12)
//used to generate data in excel document
void test()
{
    Search algo;
    for(int i = 0; i < 9; i++)
    {
        cout << "Number of Nodes: " << i+4 << endl << endl;
        for(unsigned int j = 0; j < 2; j++)
        {
            algo.Load(4+i);
            algo.Select(j);
            algo.Execute();
            algo.Stats();
        }

        cout << "------------------------------------------" << endl << endl;
    }
}

//runs the whole program
int main()
{
    //test();
    Search algo;
    for(unsigned int i = 0; i < 2; i++)
    {
        algo.Load();
        algo.Select(i);
        algo.Execute();
        //algo.Display(); //uncomment to see every path tested
        //algo.Save();
        algo.Stats();
    }

    return 0;
}
