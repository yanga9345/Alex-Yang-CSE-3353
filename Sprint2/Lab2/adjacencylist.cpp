#include "adjacencylist.h"

//constructors
adjacencylist::adjacencylist()
{

    int curr = 0;

}

//adjacencylist::adjacencylist(char* in)
//{
//    int curr = 0;
//    FileIO sources;

//    sources.Parse_flights(in);
//    flights = sources.get();
//    numSources = sources.getSize();
//    for(int i = 0; i < numSources; i++)
//    {
//        its.add(curr);
//    }
//}

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
