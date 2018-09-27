#include "search.h"

Search::Search()
{

//    algorithms.push_back(SearchAlgo::BubbleSort);
//    algorithms.push_back(SearchAlgo::InsertionSort);
//    algorithms.push_back(SearchAlgo::MergeSort);

//    algorithms.push_back(SearchAlgo::DFSIterative);
      algorithms.push_back(SearchAlgo::DFSRecursive);
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
    source = atoi(argv[1]);
    destination = atoi(argv[2]);
    char *c = new char[15];
    std::string s_num;
    int loop = 0;
    int v, e;
    int v1, v2, comma, start = 0;

    ifstream graphFile("graph.txt");
    ifstream weightsFile("weights.txt");
    ifstream positionsFile("positions.txt");

    while(graphFile.getline(c, 15))
    {
        graphFile.getline(c, 15);
        s_num = string(c);
        size_t n = std::count(s_num.begin(), s_num.end(), ',');
        comma = s_num.find(',');

        v1 = stoi(s_num.substr(start, comma));
    }

    start = 0;
    graph = Graph(v1);
    Source s1;
    dest d1;

    graphFile.clear();
    graphFile.seekg(0);
    while(graphFile.getline(c, 15))
    {
        graphFile.getline(c, 15);
        s_num = string(c);
        size_t n = std::count(s_num.begin(), s_num.end(), ',');
        int count = 0;
        for(int i = 0; i < int(n) + 1; i++)
        {
            comma = s_num.find(',');
            v2 = stoi(s_num.substr(start, comma));
            if(i == 0)
            {
                v1 = v2;
                s1 = Source(v1);
                sources.add(s1);
                count++;
            }
            else
            {
                graph.addEdge(v1, v2);
                d1 = dest(v2);
                sources[count-1].addDest(d1);
            }
            s_num = s_num.substr(comma + 1, s_num.length()-comma);
        }
    }

    delete[] c;
    graphFile.close();


    while(positionsFile.getline(c, 15))
    {
        positionsFile.getline(c, 15);
        s_num = string(c);
        size_t n = std::count(s_num.begin(), s_num.end(), ',');
        int count = 0;
        for(int i = 0; i < int(n) + 1; i++)
        {
            comma = s_num.find(',');
            v2 = stoi(s_num.substr(start, comma));
            if(i == 0)
            {

                v1 = v2;
                s1 = Source(v1);

            }
            else
            {
                graph.addEdge(v1, v2);
                d1 = dest(v2);
                sources[count-1].addDest(d1);
            }
            s_num = s_num.substr(comma + 1, s_num.length()-comma);
        }
    }
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
    sortName = activeAlgo(sources, source, destination);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    runTime = elapsed.count();
}

//prints the sorted vector
void Search::Display()
{
    for(int i = 0; i < sources.getSize(); i++)
    {
        sources[i].print();
    }
    cout << endl;
}

//displays the file, sorting method used, and time it took to run
void Search::Stats()
{
    //cout << "File: " << filename << endl;
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
