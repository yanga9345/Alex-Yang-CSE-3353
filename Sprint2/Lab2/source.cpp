#include "source.h"

Source::Source()
{
    links = 0;
}

Source::Source(int id)
{
    this->id = id;
    links = 0;
}

void Source::addDest(dest destination)
{
    destinations.add(destination);
    links++;
}

//checks to see if the source contains a specific destination
bool Source::contains(int d)
{
    for(int i = 0; i < links; i++)
    {
        if (destinations[i].getID() == d)
            return true;
    }
    return false;
}

//returns the index of an element in the source's destinations
int Source::locationOf(int d)
{
    for(int i = 0; i < links; i++)
    {
        if (destinations[i].getID() == d)
            return i;
    }
    return links;
}

//overloaded = operator
Source& Source::operator=(Source s)
{
    this->id = s.id;
    destinations = s.destinations;
    links = s.links;
    return *this;
}

//overloaded == operator
bool Source::operator==(Source s)
{
    if(this->id == s.id)
    {
        return true;
    }
    return false;
}

//getters

DLinkedList<dest>& Source::getDestinations()
{
    return destinations;
}

dest& Source::getDestination(int index)
{
    return destinations[index];
}

int Source::getSize()
{
    return links;
}

//displays the source's name and its destination information
void Source::print()
{
    cout << "Source: " << id;
    cout << "     Pos: (" << x << "," << y << "," << z << ")" << std::endl;
    cout << endl;
    for(int i = 0; i < links; i++)
    {
        destinations[i].print();

    }
    cout << "\n" << endl;
}

int Source::getID()
{
    return id;
}

void Source::setPosition(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
