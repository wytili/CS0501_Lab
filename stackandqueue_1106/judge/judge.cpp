#include <iostream>
#include "judge.h"

using namespace std;

queue::queue()
{
    front = rear = NULL;
}

queue::~queue()
{
    node *tmp;
    while(front != NULL)
    {
        tmp = front;
        front = front -> next;
        delete tmp;
    }
}

void queue::enqueue(const int &x)
{
    if(isempty())
        {front = rear = new node(x);}
    else
        {rear = rear -> next = new node(x);}
}

int queue::dequeue()
{
    node *tmp = front;
    int x = tmp -> data;
    front = front -> next;
    if(front == NULL){rear = NULL;}
    delete tmp;
    return x;
}

int queue::gethead()
{
    return front -> data;
}

bool queue::isempty()
{
    return front == NULL;
}

stack::stack()
{
    upper = NULL;
}

stack::~stack()
{
    node *tmp;
    while(upper != NULL)
    {
        tmp = upper;
        upper = upper -> next;
        delete tmp;
    }
}

bool stack::isEmpty()
{
    return upper == NULL;
}

int stack::pop()
{
    node *tmp = upper;
    int x = tmp -> data;
    upper = upper -> next;
    delete tmp;
    return x;
}

void stack::push(const int &x)
{
    upper = new node(x, upper);
}
 
int stack::top()
{
    return upper -> data;
}


