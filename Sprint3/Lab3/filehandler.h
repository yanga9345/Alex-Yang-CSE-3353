#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <vector>
#include <iostream>
#include <fstream>
#include "node.h"
#include <iomanip>

class FileHandler
{
private:
    vector<Node> vec;
public:
    FileHandler();
    void readFile(vector<Node> &in);
    vector<Node> loadGraph();
    void outputResults(string, vector<int>, float, double);
    void clearFile();

};

#endif // FILEHANDLER_H
