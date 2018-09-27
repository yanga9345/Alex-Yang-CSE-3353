#ifndef NODE_H
#define NODE_H

using namespace std;

//node class
template<typename t>
struct node
{
    t data;
    node* next;
    node* prev;
};


#endif // NODE_H
