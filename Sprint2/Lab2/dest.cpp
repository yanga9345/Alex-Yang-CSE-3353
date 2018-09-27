#include "dest.h"

//constructors
dest::dest()
{
    id = 0;
    weight = 0;
    time = 0;
}

dest::dest(int new_id)
{
    id = new_id;
    weight = 0;
    time = 0;
}

dest::dest(int new_id, int new_weight, int new_time)
{
    id = new_id;
    weight = new_weight;
    time = new_time;
}

dest& dest::operator=(const dest& d)
{
    this->id = d.id;
    weight = d.weight;
    time = d.time;

    return *this;
}

//setters

void dest::setWeight(int in)
{
    weight = in;
}

//getters

int dest::getID()
{
    return id;
}

int dest::getWeight()
{
    return weight;
}

int dest::getTime()
{
    return time;
}

//outputs formatted information on the dest
void dest::print()
{
    std::cout << "  dest: " << id << "     Weight: " << weight;
    std::cout << "  Pos: (" << x << "," << y << "," << z << ")" << std::endl;
}

void dest::set(int new_id, int new_weight, int new_time)
{
    id= new_id;
    weight = new_weight;
    time = new_time;
}

void dest::setPosition(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
