#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <vector>
#include <iostream>
#include <fstream>
#include "node.h"

class FileHandler
{
private:
    vector<Node> vec;
public:
    FileHandler();
    void readFile(vector<Node> &in);
    vector<Node> loadGraph();

};

#endif // FILEHANDLER_H
