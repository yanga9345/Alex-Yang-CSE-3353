#include "search.h"

Search::Search()
{
    algorithms.push_back(SearchAlgo::DFSRecursive);
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
    int v1, v2, comma, start = 0;

    ifstream graphFile("graph.txt");
    ifstream weightsFile("weights.txt");
    ifstream positionsFile("positions.txt");

    while(graphFile.getline(c, 15))
    {
        graphFile.getline(c, 15);
        s_num = string(c);
        //size_t n = std::count(s_num.begin(), s_num.end(), ',');
        comma = s_num.find(',');

        v1 = stoi(s_num.substr(start, comma));
    }

    start = 0;
    //graph = Graph(v1);
    Source s1;
    dest d1;

    graphFile.clear();
    graphFile.seekg(0);

    double x, y, z;
    string temp = "";
    int id;
    int location = 0;

    int count = 0;
    while(graphFile.getline(c, 50))
    {
        //graphFile.getline(c, 50);
        s_num = string(c);
        size_t n = std::count(s_num.begin(), s_num.end(), ',');
        for(int i = 0; i < int(n) + 1; i++)
        {
            comma = s_num.find(',', start);
            temp = s_num.substr(start, comma);
            v2 = stoi(temp);
            if(i == 0)
            {
                v1 = v2;
                s1 = Source(v1);
                sources.add(s1);
                count++;
            }
            else
            {
                d1 = dest(v2);
                s_num = string(c);

                location = sources[count-1].locationOf(v2);

                if(sources[count-1].contains(v2))
                {
                    //cout << "yes" << endl;
                }
                else
                {
                    d1 = dest(v2);
                    sources[count-1].addDest(d1);
                }
            }
            start = comma + 1;

        }
    }


    graphFile.close();

    //reads in all the position data
    while(positionsFile.getline(c, 50))
    {
        s_num = string(c);

        comma = s_num.find(',');
        id = stoi(s_num.substr(start, comma));
        s_num = s_num.substr(comma + 1, s_num.length()-comma);

        comma = s_num.find(',');
        x = stof(s_num.substr(start, comma));
        s_num = s_num.substr(comma + 1, s_num.length()-comma);

        comma = s_num.find(',');
        y = stof(s_num.substr(start, comma));
        s_num = s_num.substr(comma + 1, s_num.length()-comma);

        comma = s_num.find(',');
        z = stof(s_num.substr(start, comma));

        for(int i = 0; i < sources.getSize(); i++)
        {
            if(sources[i].getID() == id)
            {
                sources[i].setPosition(x, y, z);
            }

            location = sources[i].locationOf(id);
            if(location < sources[i].getSize())
            {
                sources[i].destinations[location].setPosition(x,y,z);
            }
        }
    }

    positionsFile.close();


    //reads in all the edge weights and assigns them to the destinations
    int w;
    while(weightsFile.getline(c, 50))
    {
        s_num = string(c);
        comma = s_num.find(',');
        v1 = stoi(s_num.substr(0, comma));
        start = comma + 1;
        comma = s_num.find(',', start);
        v2 = stoi(s_num.substr(start, comma));
        w = stoi(s_num.substr(comma + 1, s_num.length() - comma - 1));

        for(int i = 0; i < sources.getSize(); i++)
        {
            if(sources[i].getID() == v1 && sources[i].contains(v2))
            {
                location = sources[i].locationOf(v2);
                sources[i].getDestination(location).setWeight(w);
            }
        }
    }
    weightsFile.close();
    al = adjacencylist(sources);
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
    cout << "Adjacency List / Graph: \n\n" << endl;
    al.print();
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
