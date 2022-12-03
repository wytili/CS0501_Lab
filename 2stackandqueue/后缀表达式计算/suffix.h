#include <iostream>
using namespace std;

#ifndef _SUFFIX_H
#define _SUFFIX_H

class linkstack
{
    private:
        struct node
        {
            double data;
            node *next;
            node(const double &x, node *p = NULL){data = x, next = p;}
            node():next(NULL){}
            ~node(){}
        };
    public:
        node *upper;
        linkstack();
        ~linkstack();
        
        bool isEmpty();
        void push(const double &x);
        double pop();
        double top();
};

#endif