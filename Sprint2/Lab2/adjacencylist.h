#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <string>
#include <list>
#include "source.h"
#include "dest.h"
//#include "fileio.h"
#include "stack.h"

#include <iostream>

//contains the adjacency list used in flight planning
class adjacencylist
{
private:
    //private data members
    std::list<Source> flights; //flights is a linked list of sources which each have their own linked list of destinations
    std::list<int> its;
    int numSources;
public:
    //public functions
    adjacencylist();
    adjacencylist(char*);
    adjacencylist& operator= (adjacencylist);

    Source& get(std::string);

    int locationOf(std::string);
    bool contains(std::string);
    int getSize();
    void print();

};

//constructors
adjacencylist::adjacencylist()
{

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
        if(flights[i].getName() == in)
            return true;
    }
    return false;
}

//returns the location of an element in the adjacency list
int adjacencylist::locationOf(std::string in)
{
    for(int i = 0; i < numSources; i++)
    {
        if(flights[i].getName() == in)
            return i;
    }
    return numSources;
}

//returns an element of the adjacency list
Source& adjacencylist::get(std::string in)
{
    for(int i = 0; i < numSources; i++)
    {
        if(flights[i].getName() == in)
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

#endif // ADJACENCYLIST_H
