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

//Sort::algorithms
//void Sort::Load(vector<int> &dat)
void Sort::Load(char* dat)
{
    intData = {};
    ifstream inFile(dat);
    char * c_string = new char[800];
    int num = 0;
    //char * temp = new char[800];
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
    activeAlgo(intData);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    cout << "RunTime: " << setprecision(3) << elapsed.count() <<
            " seconds " << endl;
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
    cout << "" << endl;
}


void Sort::Save()
{

}
