#include <iostream>
using namespace std;

#ifndef _LUNCH_H
#define _LUNCH_H

class queue
{
    public:
        struct node
        {
            int data;
            node *next;
            node(const int &x, node *p = NULL){data = x, next = p;}
            node():next(NULL){}
            ~node(){}
        };

        node *front, *rear;
        queue();
        ~queue();
        bool isempty();
        void enqueue(const int &x);
        int dequeue();
        int gethead(); 
};

#endif
