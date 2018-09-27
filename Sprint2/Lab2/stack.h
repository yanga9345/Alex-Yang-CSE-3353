#ifndef DSSTACK_H
#define DSSTACK_H

#include <string>
#include <list>
#include "node.h"

using namespace std;
template<typename t>
class Stack
{
private:
    //private data members
    std::list<t> linkedlist;
public:
    //public functions
    Stack();
    t peek();
    bool contains(int);
    void push(t in);
    void pop();
    bool isEmpty();

    std::list<t>& getStack();
};

template<typename t>
Stack<t>::Stack()
{

}

//returns top of stack
template<typename t>
t Stack<t>::peek()
{
    t result;
    while(linkedlist.hasNext())
        linkedlist.temp = linkedlist.temp->next;
    result = linkedlist.temp->data;

    return result;
}

//checks to see if a value is contained within the stack
template<typename t>
bool Stack<t>::contains(int cmp)
{
    return linkedlist.contains(cmp);
}

//adds element to stack
template<typename t>
void Stack<t>::push(t in)
{
    linkedlist.add(in);
}

//removes the top element of the stack
template<typename t>
void Stack<t>::pop()
{
    if(!isEmpty())
    {
        node<t>* oldTemp = linkedlist.temp;
        linkedlist.temp = oldTemp->next;
        delete oldTemp;
    }
}

//returns true if stack is empty
template<typename t>
bool Stack<t>::isEmpty()
{
    return linkedlist.isEmpty();
}

//returns the linkedlist within the stack
template<typename t>
std::list<t>& Stack<t>::getStack()
{
    return linkedlist;
}

#endif // DSSTACK_H
