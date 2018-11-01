#include "search.h"

Search::Search()
{
    algorithms.push_back(SearchAlgo::Brute_Force);
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
    int comma, start = 0;

    ifstream positionsFile("positions.txt");

    float x, y, z;
    string temp = "";
    int id;

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


        //std::cout << x << " " << y << " " << z << endl;
        vec.push_back(Node(id, x, y, z));
    }
    positionsFile.close();
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
    sortName = activeAlgo(vec, source, destination);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    runTime = elapsed.count();
}

//prints the sorted vector
void Search::Display()
{
    cout << "Graph: \n\n" << endl;
    for(int i = 0; i < vec.size(); i++)
    {
        vec[i].print();
    }
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
