#include <iostream>
#include "link.h"

using namespace std;

void link::clear()
{
    node *p = head -> next, *q;
    while(p != NULL)
    {
        q = p -> next;
        delete p;
        p = q;
    }
    head -> next = NULL;
    CurrentLength = 0;
}

link::link(int i)
{
    node *tmp, *p;
    head = new node;
    tail = new node;
    tmp = head;
    for(int x = 0; x < i; x++)
    {
        p = new node;
        if(x == 0){head -> next = p;tmp = p;}
        p -> data = x + 1;
        tmp -> next = p;
        tmp = p;
    }
    tail = tmp;
    tail -> next = head -> next;
    CurrentLength = i;
}

void link::remove(int i)
{
    node *p, *d;
    p = move(i - 2);
    d = p -> next;
    p -> next = d -> next;
    head = p;
    cout << d -> data << ' ';
    delete d;
    --CurrentLength;
}

void link::traverse()
{
    node *p = move(0);
    cout << endl;
    for(int i = 0; i < 12; i++)
    {
        cout << p -> data <<' ';
        p = p -> next;
    }
    cout<<endl;
}