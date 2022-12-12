#include <iostream>
using namespace std;

#ifndef _BST_H
#define _BST_H

class BiSearchTree
{
    public:
        struct BiNode
        {
            string data;
            BiNode *left;
            BiNode *right;
            BiNode(const string &data, BiNode *lt = NULL, BiNode *rt = NULL): data(data), left(lt), right(rt){} 
        };
        BiNode *root;
        int num;
        BiSearchTree();
        ~BiSearchTree();
        // string *find(const string &x);
        // void insert(const string &x);
        void remove(string x);
        void trimBST(int low, int high, BiNode *&t);
        void createTree();
        void levelOrder();
    
    private:
        // void insert(const string &x, BiNode *&t);
        void remove(string x, BiNode *&t);
        // string *find(const string &x, BiNode *&t);
        void makeEmpty(BiNode *t);
};

class queue
{
    public:
        struct node
        {
            BiSearchTree::BiNode *data;
            node *next;
            node( BiSearchTree::BiNode *x, node *p = NULL){data = x, next = p;}
            node():next(NULL){}
            ~node(){}
        };

        node *front, *rear;
        queue();
        ~queue();
        bool isempty();
        void enqueue(BiSearchTree::BiNode *x);
        BiSearchTree::BiNode *dequeue();
};

#endif