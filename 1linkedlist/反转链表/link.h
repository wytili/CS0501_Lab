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
            node *next, *prev;
            node(const int &x, node *n = NULL, node *p = NULL){data = x; next = n; prev = p;}
            node():next(NULL), prev(NULL){}
            ~node(){}
        };
        node *head, *tail;
        int CurrentLength;

        link();
        ~link(){clear(); delete head; delete tail;}
        void clear();
        void ForwardTraverse(int start, int end);
        void BackwardTraverse(int end, int start);
        void insert(int i, const int &x);
        node *move(int i) const
        {
            node *p = head;
            while(i >= 0)
            {
                p = p -> next;
                i--;
            }
            return p;
        }
};


#endif