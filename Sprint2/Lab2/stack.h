#ifndef DSSTACK_H
#define DSSTACK_H

#ifndef Stack_H
#define Stack_H
#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity of Stack
#define SIZE 10

// Class for Stack
template <typename T>
class Stack
{
    T *arr;
    int top;
    int capacity;

public:
    Stack(int size = SIZE);	// constructor

    void push(T);
    T pop();
    T peek();

    int size();
    bool isEmpty();
    bool isFull();
};

// Constructor to initialize Stack
template <typename T>
Stack<T>::Stack(int size)
{
    arr = new T[size];
    capacity = size;
    top = -1;
}

// function to add an element x in the Stack
template <typename T>
void Stack<T>::push(T x)
{
    if (isFull())
    {
        cout << "OverFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << x << endl;
    arr[++top] = x;
}

// function to pop top element from the Stack
template <typename T>
T Stack<T>::pop()
{
    // check for Stack underflow
    if (isEmpty())
    {
        cout << "UnderFlow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << peek() << endl;

    // decrease Stack size by 1 and (optionally) return the popped element
    return arr[top--];
}

// function to return top element in a Stack
template <typename T>
T Stack<T>::peek()
{
    if (!isEmpty())
        return arr[top];
    else
        exit(EXIT_FAILURE);
}

// Utility function to return the size of the Stack
template <typename T>
int Stack<T>::size()
{
    return top + 1;
}

// Utility function to check if the Stack is empty or not
template <typename T>
bool Stack<T>::isEmpty()
{
    return top == -1;	// or return size() == 0;
}

// Utility function to check if the Stack is full or not
template <typename T>
bool Stack<T>::isFull()
{
    return top == capacity - 1;	// or return size() == capacity;
}


#endif // Stack_H

#endif // DSSTACK_H
