#ifndef DEST_H
#define DEST_H

#include <string>
#include <iostream>

//contains dest information
class dest
{
private:
    //private data members
    int id;
    int weight, time;
    double x, y, z;
public:
    //public functions
    dest();
    dest(int);
    dest(int, int, int);
    dest& operator=(const dest&);
    void setWeight(int);
    int getID();
    int getWeight();
    int getTime();
    void print();
    void set(int, int, int);
    void setPosition(double, double, double);
};

#endif // DEST_H
