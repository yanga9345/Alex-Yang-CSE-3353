#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "node.h"

//fileHandler class manages reading and writing to files
class FileHandler
{
private:
    vector<Node> vec; //adjacency list representation of a graph
public:
    FileHandler();
    void readFile(vector<Node> &in); //instantiates the adjacency list
    vector<Node> loadGraph(); //reads the file data into the adjacency list and returns the resulting adjacency list
    void outputResults(string, vector<int>, float, double); //outputs algorithm data into txt files
    void clearFile(); //deletes the contents of a file (not used in code)

};

#endif // FILEHANDLER_H
