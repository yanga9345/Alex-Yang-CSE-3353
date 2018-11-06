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
public:
    Node();
    Node(int, float, float, float);

    bool operator<(Node in);

    bool operator>(Node in);

    int getID();
    float getX();
    float getY();
    float getZ();

    void print();

    float getDistance(Node);
};


#endif // Node_H
