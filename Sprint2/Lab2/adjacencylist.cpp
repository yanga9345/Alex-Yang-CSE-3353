#include "adjacencylist.h"

//constructors
adjacencylist::adjacencylist()
{
}

adjacencylist::adjacencylist(DLinkedList<Source> in)
{
    flights = in;
    numSources = in.getSize();
}

//checks to see if an element is in adjacency list
bool adjacencylist::contains(int in)
{
    for(int i = 0; i < numSources; i++)
    {
        if(flights[i].getID() == in)
            return true;
    }
    return false;
}

//returns the location of an element in the adjacency list
int adjacencylist::locationOf(int in)
{
    for(int i = 0; i < numSources; i++)
    {
        if(flights[i].getID() == in)
            return i;
    }
    return numSources;
}

//returns an element of the adjacency list
Source& adjacencylist::get(int in)
{
    for(int i = 0; i < numSources; i++)
    {
        if(flights[i].getID() == in)
            return flights[i];
    }
    return flights[0];
}

//overloaded = operator
adjacencylist& adjacencylist::operator= (adjacencylist al2)
{
    flights = al2.flights;
    numSources = al2.numSources;
    return *this;
}

int adjacencylist::getSize()
{
    return numSources;
}

//displays flight information
void adjacencylist::print()
{
    for(int i = 0; i < flights.getSize(); i++)
    {
        flights[i].print();
    }
}


void adjacencylist::DFSIterative(int, int)
{

}

void adjacencylist::DFSRecursive(int, int)
{

}

void adjacencylist::BFSIterative(int, int)
{

}

void adjacencylist::BFSRecursive(int, int)
{

}

void adjacencylist::Dijkstra(int, int)
{

}

void adjacencylist::AStar(int, int)
{

}
