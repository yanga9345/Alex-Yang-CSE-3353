#include <node.h>

Node::Node()
{
    visited = false;
}

Node::Node(int in, float x, float y, float z)
{
    visited = false;
    id = in;
    this->x = x;
    this->y = y;
    this->z = z;
}



void Node::addConnection(Node &in)
{
    connections.push_back(in);
}

//getters

vector<Node> Node::getConnections()
{
    return connections;
}

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

//outputs the id and coordinates of a node
void Node::print()
{
    std::cout << id << ": (" << x << "," <<
                 y <<  "," << z << ")" << endl;
}

//returns a representation of the distance between nodes
float Node::getDistance(Node n2)
{
    float dist = this->x - n2.getX() + this->y - n2.getY();
    if(dist < 0)
        return (dist * -1);
    else
        return dist;
}
