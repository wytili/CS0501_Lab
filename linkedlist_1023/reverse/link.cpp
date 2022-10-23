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

link::link()
{
    head = new node;
    head -> next = tail = new node;
    tail -> prev = head;
    CurrentLength = 0;
}

void link::ForwardTraverse(int start, int end)
{
    node *first = move(start);

    while(first != move(end + 1))
    {
        cout << first -> data <<' ';
        first = first -> next;
    }
}

void link::BackwardTraverse(int end, int start)
{
    node *first = move(end);

    while(first != move(start - 1))
    {
        cout << first -> data <<' ';
        first = first -> prev;
    }
}

void link::insert(int i, const int &x)
{
    node *pos, *tmp;

    pos = move(i);
    tmp = new node(x, pos, pos -> prev);
    pos -> prev -> next = tmp;
    pos -> prev = tmp;

    ++CurrentLength;
}