#include "search.h"

Search::Search()
{
    algorithms.push_back(TSP_Algo::SA);
    algorithms.push_back(TSP_Algo::PSO);
    algorithms.push_back(TSP_Algo::Brute_Force);
    algorithms.push_back(TSP_Algo::Dynamic_Programming);
}

void Search::Load()
{
    vec.clear();
    f.readFile(vec);
    vec = f.loadGraph();
}

void Search::Load(int count)
{
    vec.clear();
    srand(time(NULL));
    for(int i = 0; i < count; i++)
    {
        float x = rand() % 11;
        float y = rand() % 11;
        float z = rand() % 11;
        vec.push_back(Node(i + 1, x, y, z));
    }
}


//selects the sorting method (Bubble, Insertion, Merge)
void Search::Select(int id)
{
    if(id < int(algorithms.size()) && id >= 0)
    {
        activeAlgo = algorithms[id];
    }
    else
    {
        cout << "Error! Cannot select that algorithm!" << endl;
    }
}

//executes the selected method
void Search::Execute()
{
    auto start = std::chrono::high_resolution_clock::now();
    bestDistance = INT8_MAX;
    algoName = activeAlgo(vec, bestPath, bestDistance, possiblePaths, possibleDistances);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    runTime = elapsed.count();
}

//prints the sorted vector
void Search::Display()
{
    std::cout << "\nPaths: " << endl;
    for(unsigned int i = 0; i < possiblePaths.size(); i++)
    {
        for(unsigned int j = 0; j < possiblePaths[i].size(); j++)
        {
            std::cout << possiblePaths[i][j];
            std::cout << " -> ";
        }
        std::cout << possiblePaths[i][0];
        std::cout << endl;
        std::cout << "Path Length: " << setprecision(3) << possibleDistances[i] << endl;
        std::cout << endl;
    }
}

//displays the file, sorting method used, and time it took to run
void Search::Stats()
{
    cout << algoName << endl << endl;

//    std::cout << "Best Path: ";
//    for(unsigned int i = 0; i < bestPath.size(); i++)
//    {
//        std::cout << bestPath[i];
//        std::cout << " -> ";
//    }
//    std::cout << bestPath[0];
//    std::cout << endl;
    std::cout << "Best Path Length: " << bestDistance << endl << endl;

    std::cout << "Run Time: " << setprecision(3) << runTime  << " seconds " << endl;
    std::cout << endl << endl;
}

//outputs sorted vectors to text files
void Search::Save()
{
    f.outputResults(algoName, bestPath, bestDistance, runTime);
}
