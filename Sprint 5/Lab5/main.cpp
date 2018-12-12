/*
 * Alex Yang
 * Professor Clark
 * CSE 3353
 * November 29th, 2018
 *
 * Lab 4: Finds an efficient Hamiltonian circuit for a given list of nodes using
 * Genetic Algorithm and Tabu List
 */

#include <iostream>
#include <fstream>
#include "search.h"

using namespace std;

//runs algorithms for different graph sizes (5, 10, 100, 200, ... , 500)
//used to generate data in excel document
void test()
{
    Search algo;

    for(int i = 4; i < 11; i++)
    {
        cout << "Number of Nodes: " << i << endl << endl;
        for(unsigned int j = 0; j < 4; j++)
        {
//            if(j != 2)
//            {
                algo.Load(i);
                algo.Select(j);
                algo.Execute();
                algo.Stats();
//            }
        }

        cout << "------------------------------------------" << endl << endl;
    }
}

//runs the whole program
int main()
{
    test();   //uncomment to see how I obtained the data for the excel sheet
//    Search algo;
//    for(unsigned int i = 0; i < 4; i++)
//    {
//        algo.Load();
//        algo.Select(i);
//        algo.Execute();
//        //algo.Display(); //uncomment to see every path tested
//        //algo.Save();
//        algo.Stats();
//    }

    return 0;
}
