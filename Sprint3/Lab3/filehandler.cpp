#include "filehandler.h"

FileHandler::FileHandler()
{
}

void FileHandler::readFile(vector<Node> &in)
{
    vec = in;
}

vector<Node> FileHandler::loadGraph()
{
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
    return vec;
}

void FileHandler::outputResults(string algoName, vector<int> bestPath, float bestDistance, double runTime)
{
    string fileName = algoName + " Solution.txt";
    ofstream outFile(fileName);

    outFile << algoName << endl << endl;

    outFile << "Best Path: ";
    for(unsigned int i = 0; i < bestPath.size(); i++)
    {
        outFile << bestPath[i];
        outFile << " -> ";
    }
    outFile << bestPath[0];
    outFile << endl;
    outFile << "Best Path Length: " << bestDistance << endl << endl;

    outFile << "Run Time: " << setprecision(3) << runTime  << " seconds " << endl;
    outFile << endl << endl;

    outFile.close();
}

void FileHandler::clearFile()
{
    std::ofstream ofs;
    ofs.open("Solution.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}
