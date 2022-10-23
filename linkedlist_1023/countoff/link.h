#include <iostream>
using namespace std;

#ifndef _LINK_H
#define _LINK_H

class link
{
    public:
        struct node
        {
            int data;
            node *next;
            node(const int &x, node *n = NULL){data = x; next = n;}
            node():next(NULL){}
            ~node(){}
        };
        node *head, *tail;
        int CurrentLength;

        link(int i);
        ~link(){clear(); delete head; delete tail;}
        void clear();
        void remove(int i);
        void traverse();
        node *move(int i) const
        {
            node *p = head;
            while(i-- >= 0)
            {
                p = p -> next;
            }
            return p;
        }
};


#endif