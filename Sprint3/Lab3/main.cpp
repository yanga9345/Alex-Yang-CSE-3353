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
            //algo.Display();
            //algo.Save();
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
        //algo.Display();
        algo.Save();
        algo.Stats();
    }

    return 0;
}
