#ifndef Node_H
#define Node_H
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//Node class

class Node
{
private:
    int id;
    float x, y, z;
    vector<Node> connections;
public:
    Node();
    Node(int, float, float, float);

    bool operator<(Node in);

    bool operator>(Node in);

    void addConnection(Node &);
    vector<Node> getConnections();
    int getID();
    float getX();
    float getY();
    float getZ();

    void print();

    float getDistance(Node);
};


#endif // Node_H
