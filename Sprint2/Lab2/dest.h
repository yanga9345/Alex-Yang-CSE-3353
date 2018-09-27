#ifndef DEST_H
#define DEST_H

#include <string>
#include <iostream>

//contains dest information
class dest
{
private:
    //private data members
    //std::string name;
    int id;
    int cost, time;
public:
    //public functions
    dest();
    dest(int, int, int);
    dest& operator=(const dest&);
    //std::string getName();
    int getID();
    int getCost();
    int getTime();
    void print();
    void set(int, int, int);
};

#endif // DEST_H
