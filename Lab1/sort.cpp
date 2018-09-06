#include "sort.h"
//#include "sortalgo.h"
//#include "algorithm.h"

Sort::Sort()
{
    //for(int i = 0; i < 3; i++)
    //    algorithms.push_back(SortAlgo.algorithms[i]);
    algorithms.push_back(SortAlgo::BubbleSort);
    algorithms.push_back(SortAlgo::InsertionSort);
    algorithms.push_back(SortAlgo::MergeSort);
}

void Sort::Load(char* dat)
{
    filename = dat;
    intData = {};
    ifstream inFile(dat);
    char * c_string = new char[800];
    int num = 0;
    while(inFile.good())
    {
        inFile.getline(c_string, 50);
        num = atoi(c_string);
        intData.push_back(num);
    }
    inFile.close();
}

void Sort::Select(int id)
{
    if(id < int(algorithms.size()) && id >= 0)
        activeAlgo = algorithms[id];
    else
    {
        cout << "Error! Cannot select that algorithm!";
    }
}

void Sort::Execute()
{
    auto start = std::chrono::high_resolution_clock::now();
    sortName = activeAlgo(intData);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    runTime = elapsed.count();
}

void Sort::Display()
{
    for(unsigned int i = 0; i < intData.size(); i++)
    {
        cout << intData[i] << " ";
    }
    cout << endl;
}

void Sort::Stats()
{
    cout << "File: " << filename << endl;
    //cout << sortName << ": " << filename << endl;
    cout << sortName << endl;
    cout << "Run Time: " << setprecision(3) << runTime  << " seconds " << endl;
    cout << endl;
}


void Sort::Save()
{
    ofstream outFile(filename + " SORTED");
    for(unsigned int i = 0; i < intData.size(); i++)
    {
        outFile << intData[i] << endl;
    }
    outFile.close();
}
