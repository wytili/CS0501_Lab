#include <iostream>
#include "suffix.h"

using namespace std;

linkstack::linkstack()
{
    upper = NULL;
}

linkstack::~linkstack()
{
    node *tmp;
    while(upper != NULL)
    {
        tmp = upper;
        upper = upper -> next;
        delete tmp;
    }
}

bool linkstack::isEmpty()
{
    return upper == NULL;
}

double linkstack::pop()
{
    node *tmp = upper;
    double x = tmp -> data;
    upper = upper -> next;
    delete tmp;
    return x;
}

void linkstack::push(const double &x)
{
    upper = new node(x, upper);
}
 
double linkstack::top()
{
    return upper -> data;
}


