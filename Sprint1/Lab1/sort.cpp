#include "sort.h"

Sort::Sort()
{
    algorithms.push_back(SortAlgo::BubbleSort);
    algorithms.push_back(SortAlgo::InsertionSort);
    algorithms.push_back(SortAlgo::MergeSort);
}

//loads data file into Sort
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

//selects the sorting method (Bubble, Insertion, Merge)
void Sort::Select(int id)
{
    if(id < int(algorithms.size()) && id >= 0)
        activeAlgo = algorithms[id];
    else
    {
        cout << "Error! Cannot select that algorithm!";
    }
}

//executes the selected method
void Sort::Execute()
{
    auto start = std::chrono::high_resolution_clock::now();
    sortName = activeAlgo(intData);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    runTime = elapsed.count();
}

//prints the sorted vector
void Sort::Display()
{
    for(unsigned int i = 0; i < intData.size(); i++)
    {
        cout << intData[i] << " ";
    }
    cout << endl;
}

//displays the file, sorting method used, and time it took to run
void Sort::Stats()
{
    cout << "File: " << filename << endl;
    cout << sortName << endl;
    cout << "Run Time: " << setprecision(3) << runTime  << " seconds " << endl;
    cout << endl;
}

//outputs sorted vectors to text files
void Sort::Save()
{
    ofstream outFile(filename + " SORTED");
    for(unsigned int i = 0; i < intData.size(); i++)
    {
        outFile << intData[i] << endl;
    }
    outFile.close();
}
