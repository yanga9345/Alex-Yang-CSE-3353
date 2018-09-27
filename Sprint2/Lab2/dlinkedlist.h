#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <iostream>
#include "node.h"

using namespace std;

//templated linkedlist class (works better than my vector)
template<typename t>
class DLinkedList
{
private:
    //private member data
    int size;

public:
    //public member data and functions
    int it;
    node<t>* head;
    node<t>* tail;
    node<t>* temp;

    //constructors
    DLinkedList();
    DLinkedList(t in);
    DLinkedList(const DLinkedList&);

    //destructor
    ~DLinkedList();

    //operators
    DLinkedList& operator= (DLinkedList&);
    t& operator[](int);
    t& getCurr();
    void resetCurr();

    //misc. functions
    node<t>* pop();
    void add(t&);
    void del(node<t> **, node<t> *);

    int getSize();
    int get();

    bool contains(t);
    int locationOf(t);
    bool hasNext();
    bool isEmpty();
    void printforward();
    void printback();

};

//constructors

template<typename t>
DLinkedList<t>::DLinkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
    it = 0;
}

template<typename t>
DLinkedList<t>::DLinkedList(t in)
{
    head->data = in;
    tail = NULL;
    size = 1;
    it = 0;
}

template<typename t>
DLinkedList<t>::DLinkedList(const DLinkedList& list2)
{
    head = list2.head;
    tail = list2.tail;
    size = list2.size;
    it = 0;
}

template<typename t>
DLinkedList<t>::~DLinkedList()
{
//    delete[] head;
//    delete[] tail;
//    temp = NULL;
}

//overloaded = operator
template<typename t>
DLinkedList<t>& DLinkedList<t>::operator= (DLinkedList &list2)
{
    head = list2.head;
    tail = list2.tail;
    for(int i = 0; i < list2.getSize(); i++)
    {
        add(list2[i]);
    }
    return (*this);
}

//overloaded [] operator
template<typename t>
t& DLinkedList<t>::operator[](int index)
{
    node<t>* save = temp;
    temp = head;
    for(int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    node<t>* out = temp;
    temp = save;
    return out->data;
}

//deals with iterating
template<typename t>
t& DLinkedList<t>::getCurr()
{
    return (*this)[it];
}

template<typename t>
void DLinkedList<t>::resetCurr()
{
    it = 0;
}

//adds elements to the Linked List
template<typename t>
void DLinkedList<t>::add(t& in)
{
    if(head == NULL)
    {
        temp = new node<t>;
        temp->data = in;
        temp->prev = NULL;
        temp->next = NULL;

        head = temp;
        tail = temp;
    }
    else
    {
        //tail = temp;

        temp = new node<t>;
        temp->data = in;
        temp->prev = tail;
        temp->next = NULL;
        tail->next = temp;
        tail = temp;
    }
    size++;
}

//deletes a node
template<typename t>
void DLinkedList<t>::del(node<t> **head, node<t> *delete_node)
{
    if(*head == NULL || delete_node == NULL)
        return;

    if(*head == delete_node)
        *head = delete_node->next;

    if(delete_node->next != NULL)
        delete_node->next->prev = delete_node->prev;

    if(delete_node->prev != NULL)
        delete_node->prev->next = delete_node->next;

    delete[] delete_node;
    return;
}

//prints list forwards
template<typename t>
void DLinkedList<t>::printforward()
{
    temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

//prints list backwards
template<typename t>
void DLinkedList<t>::printback()
{
    temp = tail;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }

    cout << endl;
}

//getters
template<typename t>
int DLinkedList<t>::get()
{
    return temp;
}

template<typename t>
int DLinkedList<t>::getSize()
{
    return size;
}

//checks to see if an element is inside the linkedlist
template<typename t>
bool DLinkedList<t>::contains(t cmp)
{
    for(int i = 0; i < size; i++)
    {
        if ((*this)[i] == cmp)
            return true;
    }

    return false;
}

//returns the location of an element in the linkedlist
template<typename t>
int DLinkedList<t>::locationOf(t cmp)
{
    for(int i = 0; i < size; i++)
    {
        if ((*this)[i] == cmp)
            return i;
    }

    return size;
}

//checks to see if iterator has next
template<typename t>
bool DLinkedList<t>::hasNext()

{
    if (temp->next != NULL)
    {
        return true;
    }
    return false;
}

//checks to see if LinkedList is empty
template<typename t>
bool DLinkedList<t>::isEmpty()
{
    if(temp == NULL)
    {
        return true;
    }
    return false;
}
#endif // DLINKEDLIST_H
