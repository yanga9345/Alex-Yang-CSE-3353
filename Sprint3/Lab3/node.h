#ifndef Node_H
#define Node_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Node class

class Node
{
private:
    int id;
    float x, y, z;
    bool visited;
    vector<Node> connections;
public:
    Node();
    Node(int, float, float, float);
    void addConnection(Node &in);
    vector<Node> getConnections();

    int getID();
    float getX();
    float getY();
    float getZ();

    void print();

    float getDistance(Node);
};


#endif // Node_H
