#include "dest.h"

//constructors
dest::dest()
{
}

dest::dest(int new_id)
{
    id = new_id;
    cost = 0;
    time = 0;
}

dest::dest(int new_id, int new_cost, int new_time)
{
    id = new_id;
    cost = new_cost;
    time = new_time;
}

dest& dest::operator=(const dest& d)
{
    this->id = d.id;
    cost = d.cost;
    time = d.time;

    return *this;
}

//getters

int dest::getID()
{
    return id;
}

int dest::getCost()
{
    return cost;
}

int dest::getTime()
{
    return time;
}

//outputs formatted information on the dest
void dest::print()
{
    std::cout << "   dest: " << id << "     cost: $" << cost;

    if(cost > 99)
    {
        std::cout << "   time: " << time << std::endl;
    }
    else
    {
        std::cout << "    time: " << time << std::endl;
    }
}

void dest::set(int new_id, int new_cost, int new_time)
{
    id= new_id;
    cost = new_cost;
    time = new_time;
}
