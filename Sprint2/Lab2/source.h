#ifndef SOURCE_H
#define SOURCE_H

#include <string>
#include "dlinkedlist.h"
#include "dest.h"

//holds information for sources
class Source
{
private:
    //private data members
    //DLinkedList<dest> destinations;
    //std::string name;
    int id;
    int links;
    double x, y, z;
public:
    DLinkedList<dest> destinations;
    //public functions
    Source();
    Source(int);
    void addDest(dest);
    int locationOf(int);
    bool contains(int);
    Source& operator=(Source);
    bool operator==(Source);
    dest& getDestination(int);
    DLinkedList<dest>& getDestinations();
    int getSize();
    void print();
    int getID();
    void setPosition(double, double, double);


};
#endif // SOURCE_H
