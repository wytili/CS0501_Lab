#include <iostream>
using namespace std;

#ifndef _AVL_H
#define _AVL_H

class AvlTree 
{
   public:
    struct AvlNode 
    {
        string data;
        AvlNode *left;
        AvlNode *right;
        int height;
        AvlNode(const string &otherdata, AvlNode *l = NULL, AvlNode *r = NULL, int h = 1)
            : data(otherdata), left(l), right(r), height(h){}
    };
    AvlNode *root;
    int flag;
    AvlTree(){root = NULL;}
    ~AvlTree() { makeEmpty(root); }
    // string* find(const string &x) const;
    // void insert(const string &x);
    // bool remove(const string &x);
    void printTree();
    void createTree();
    void isAVL(AvlNode *t);

   private:
    // void insert(const string &x, AvlNode *&t);
    // bool remove(const string &x, AvlNode *&t);
    // bool adjust(AvlNode *&t, string subtree);
    void makeEmpty(AvlNode *&t);
    int height(AvlNode *t);
    // void LL(AvlNode *&t);
    // void RR(AvlNode *&t);
    // void LR(AvlNode *&t);
    // void RL(AvlNode *&t);
};

class queue
{
    public:
        struct node
        {
            AvlTree::AvlNode *data;
            node *next;
            node(AvlTree::AvlNode *x, node *p = NULL){data = x, next = p;}
            node():next(NULL){}
            ~node(){}
        };

        node *front, *rear;
        queue();
        ~queue();
        bool isempty();
        void enqueue(AvlTree::AvlNode *x);
        AvlTree::AvlNode *dequeue();
};

#endif