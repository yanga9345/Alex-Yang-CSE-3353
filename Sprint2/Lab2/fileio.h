#ifndef FILEIO_H
#define FILEIO_H

#include "dlinkedlist.h"
#include "source.h"

class fileIO
{
public:
    fileIO();
    void parse();
    DLinkedList<Source> getList();
private:
    DLinkedList<Source> sources;
    //int source, destination;
};

fileIO::fileIO()
{

}

void fileIO::parse()
{
    char *c = new char[15];
    std::string s_num;
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

#endif // FILEIO_H
