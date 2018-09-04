#include "sort.h"
//#include "sortalgo.h"
//#include "algorithm.h"

Sort::Sort()
{

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
    activeAlgo = algorithms[id];
}

void Sort::Exe()
{
    //activeAlgo(intData);
}

void Sort::Display()
{
    for(unsigned int i = 0; i < intData.size(); i++)
    {
        cout << intData[i] << " ";
    }
}
