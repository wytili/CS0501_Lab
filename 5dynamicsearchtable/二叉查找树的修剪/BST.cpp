#include <iostream>
#include <string>
#include "BST.h"
using namespace std;

BiSearchTree::BiSearchTree()
{
    root = NULL;
}

BiSearchTree::~BiSearchTree()
{
    makeEmpty(root);
}

void BiSearchTree::makeEmpty(BiNode *t)
{
    if(t == NULL)return;
    makeEmpty(t -> left);
    makeEmpty(t -> right);
    delete t;
}

void BiSearchTree::remove(string x)
{
    return remove(x, root);
}

void BiSearchTree::remove(string x, BiNode *&t)
{
    if( t == NULL || t -> data =="null") return; 
    else if ( stoi(x) < stoi(t->data) ) remove( x, t->left );
    else if( stoi(x) > stoi(t->data) ) remove( x, t->right );
    else if( t->left != NULL && t->right != NULL && t -> left ->data != "null" && t->right ->data != "null") 
        { 
            BiNode *tmp = t->left;
            while (tmp->right != NULL && tmp -> right ->data != "null") tmp = tmp->right; 
            t->data = tmp->data;
            remove( t->data, t->left );
        }
    else if((t->left == NULL||t -> left ->data == "null") && (t->right == NULL||t -> right ->data == "null"))
        {
            t -> data = "null";  
            num--;
        }
    else
        { 
            BiNode *oldNode = t;
            t = ( t->left != NULL && t -> left ->data != "null") ? t->left : t->right;
            delete oldNode;
            num--;
        }
}

void BiSearchTree::trimBST(int low, int high, BiNode *&t)
{
    if(t == NULL || t -> data == "null")return;
    else if(stoi(t -> data) >= low && stoi(t -> data) <= high)
    {
        trimBST(low, high, t -> left);
        trimBST(low, high, t -> right);
    }
    else if(stoi(t -> data) < low || stoi(t -> data) > high)
    {
        remove(t -> data);
        trimBST(low, high, t);
    }
}

void BiSearchTree::createTree()
{
    queue que;
    BiNode *tmp;
    string x;
    num = 1;
    cin >> x;
    root = new BiNode(x);
    if(cin.get() == '\n'){/*cout<< "created!" << endl;*/ return;}//change '\n' to EOF in online judging
    que.enqueue(root);
    while(cin >> x)
    {
        tmp = que.dequeue();

        if(x != "null")num++;
        que.enqueue(tmp -> left = new BiNode(x));
        if(cin.get() == '\n'){break;}

        cin >> x;
        if(x != "null")num++;
        que.enqueue(tmp -> right = new BiNode(x));
        if(cin.get() == '\n'){break;}
    }
    // cout << "created!" << endl;
}

void BiSearchTree::levelOrder()
{
    queue que;
    que.enqueue(root);
    while (num)
    {
        BiNode* tmp = que.dequeue();
        if (tmp->data != "null") 
        {
            cout << tmp->data << ' ';
            num--;
        }
        else cout << "null" << ' ';
        if (tmp->left) que.enqueue(tmp->left);
        else que.enqueue(new BiNode("null"));
        if (tmp->right) que.enqueue(tmp->right);
        else que.enqueue(new BiNode("null"));
    }
}

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

void queue::enqueue(BiSearchTree::BiNode *x)
{
    if(isempty())
        {front = rear = new node(x);}
    else
        {rear = rear -> next = new node(x);}
}

BiSearchTree::BiNode *queue::dequeue()
{
    node *tmp = front;
    BiSearchTree::BiNode *x = tmp -> data;
    front = front -> next;
    if(front == NULL){rear = NULL;}
    delete tmp;
    return x;
}

bool queue::isempty()
{
    return front == NULL;
}

// void BiSearchTree::insert(const string &x)
// { 
//     insert( x, root );
// }

// void BiSearchTree::insert(const string &x, BiNode *&t)
// { 
//     if(t == NULL) t = new BiNode(x, NULL, NULL);
//     else if(x < t->data) insert(x, t->left);
//     else if(t->data < x) insert(x, t->right);
// }


// string* BiSearchTree::find(const string &x)
// {
//     return find(x, root);
// }

// string* BiSearchTree::find(const string &x, BiNode *&t)
// {
//     if(t == NULL || t -> data ==x) return (string*)t;
//     if(x < t -> data) return find(x, t -> left);
//     else return find(x, t -> right);
// } 