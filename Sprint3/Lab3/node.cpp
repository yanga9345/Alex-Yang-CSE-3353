#include "node.h"

Node::Node()
{
    //visited = false;
}

Node::Node(int in, float x, float y, float z)
{
    //visited = false;
    id = in;
    this->x = x;
    this->y = y;
    this->z = z;
}



//void Node::addConnection(Node &in)
//{
//    connections.push_back(in);
//}

//getters

//vector<Node> Node::getConnections()
//{
//    return connections;
//}

int Node::getID()
{
    return id;
}

float Node::getX()
{
    return x;
}

float Node::getY()
{
    return y;
}

float Node::getZ()
{
    return z;
}

bool Node::operator<(Node in)
{
    if(this->id < in.getID())
        return true;
    return false;
}

bool Node::operator>(Node in)
{
    if(this->id > in.getID())
        return true;
    return false;
}

//outputs the id and coordinates of a node
void Node::print()
{
    std::cout << id << ": (" << x << "," <<
                 y <<  "," << z << ")" << endl;
}

//returns a representation of the distance between nodes
float Node::getDistance(Node n2)
{
    float XDist = this->x - n2.getX();
    float YDist = this->y - n2.getY();
    float ZDist = this->z - n2.getZ();

    return sqrt(XDist * XDist + YDist * YDist + ZDist * ZDist);
}
