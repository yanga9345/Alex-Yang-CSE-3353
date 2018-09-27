#include "search.h"

Search::Search()
{

//    algorithms.push_back(SearchAlgo::BubbleSort);
//    algorithms.push_back(SearchAlgo::InsertionSort);
//    algorithms.push_back(SearchAlgo::MergeSort);

//    algorithms.push_back(SearchAlgo::DFSIterative);
//    algorithms.push_back(SearchAlgo::DFSRecursive);
//    algorithms.push_back(SearchAlgo::BFSIterative);
//    algorithms.push_back(SearchAlgo::BFSRecursive);
//    algorithms.push_back(SearchAlgo::Dijkstra);
//    algorithms.push_back(SearchAlgo::AStar);

}

//loads data file into Sort
void Search::Load(char* dat)
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

void Search::Load(char ** argv)
{
    char c;
    std::string temp;
    int input, loop = 0;
    int v, e;

    ifstream graphFile("graph.txt");
    ifstream weightsFile("weights.txt");
    ifstream positionsFile("positions.txt");

    while(graphFile)
    {
        graphFile >> c;
        if(c == ',')
        {
            loop++;
            if(loop == 1)
            {
                v = stoi(temp);
                graph.addVertices(v);
            }
            else
            {
                e = stoi(temp);
                graph.addEdge(v, e);
            }
            temp = "";
        }
        else if(c == '\n')
        {
            loop = 0;
        }
        else
        {
            temp += c;
        }
    }

    graphFile.close();
    weightsFile.close();
    positionsFile.close();
}

//selects the sorting method (Bubble, Insertion, Merge)
void Search::Select(int id)
{
    if(id < int(algorithms.size()) && id >= 0)
    {
        activeAlgo = algorithms[id];
        //activeAlgo = SearchAlgo::BFSIterative;
    }
    else
    {
        cout << "Error! Cannot select that algorithm!";
    }
}

//executes the selected method
void Search::Execute()
{
    auto start = std::chrono::high_resolution_clock::now();
    sortName = activeAlgo(source, dest);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    runTime = elapsed.count();
}

//prints the sorted vector
void Search::Display()
{
    for(unsigned int i = 0; i < intData.size(); i++)
    {
        cout << intData[i] << " ";
    }
    cout << endl;
}

//displays the file, sorting method used, and time it took to run
void Search::Stats()
{
    cout << "File: " << filename << endl;
    cout << sortName << endl;
    cout << "Run Time: " << setprecision(3) << runTime  << " seconds " << endl;
    cout << endl;
}

//outputs sorted vectors to text files
void Search::Save()
{
    ofstream outFile(filename + " SORTED");
    for(unsigned int i = 0; i < intData.size(); i++)
    {
        outFile << intData[i] << endl;
    }
    outFile.close();
}
