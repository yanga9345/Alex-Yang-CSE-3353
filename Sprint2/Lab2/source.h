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
    DLinkedList<dest> destinations;
    //std::string name;
    int id;
    int links;
public:
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
    //std::string getName();
    int getID();

};
#endif // SOURCE_H
