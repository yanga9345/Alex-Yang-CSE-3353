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
