#include <iostream>
#include "lca.h"

using namespace std;

btree::~btree()
{
    clear(root);
}

void btree::clear(Node *&t)
{
    if(t == NULL) return;
    clear(t -> left);
    clear(t -> right);
    delete t;
    t = NULL;
}

void btree::levelOrder()
{
    queue q;
    Node *tmp;
    string output;

    cout << "LevelOrder:" << endl;
    q.enqueue(root);

    while(!q.isempty())
    {
        tmp = q.dequeue();
        cout << tmp->data << " ";
        if (tmp->left != NULL)
            q.enqueue(tmp->left);
        if(tmp->right != NULL)
            q.enqueue(tmp->right);
    }
}

void btree::createTree()
{
    queue que;
    Node *tmp;
    string x;
    cin >> x;
    root = new Node(x, size, 0);
    if(cin.get() == '\n'){return;}
    que.enqueue(root);
    while(cin >> x)
    {
        tmp = que.dequeue();
        size++;
        que.enqueue(tmp -> left = new Node(x, size, 0));
        tmp -> left -> rdad = tmp;
        if(cin.get() == '\n'){break;}
        cin >> x;
        size++;
        que.enqueue(tmp -> right = new Node(x, size, 0));
        tmp -> right -> ldad = tmp;
        if(cin.get() == '\n'){break;}
    }
}

btree::Node* btree::findNode(int n, btree::Node* t)
{
    btree::Node *tmp;
    if(t == NULL || t -> data == "null"){return NULL;}
    if(t -> number == n){return t;}
    if((tmp = findNode(n, t -> left))){return tmp;}
    else {return findNode(n, t -> right);}
}

void btree::Ancester(btree::Node* a, btree::Node* b)
{
    if(a == NULL || a -> data == "null" || b == NULL || b -> data == "null"){cout << "bad input"; return;}
    while(a != root)
    {
        a -> flag ++;
        if(a -> rdad == NULL && a -> ldad != NULL){a = a -> ldad;}
        else if(a -> ldad == NULL && a -> rdad != NULL){a = a -> rdad;}
    }
    root -> flag ++;

    while(1)
    {
        b -> flag ++;
        if(b -> flag == 2){cout << b -> data; break;}
        if(b -> rdad == NULL && b -> ldad != NULL){b = b -> ldad;}
        else if(b -> ldad == NULL && b -> rdad != NULL){b = b -> rdad;}
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

void queue::enqueue(btree::Node *x)
{
    if(isempty())
        {front = rear = new node(x);}
    else
        {rear = rear -> next = new node(x);}
}

btree::Node *queue::dequeue()
{
    node *tmp = front;
    btree::Node *x = tmp -> data;
    front = front -> next;
    if(front == NULL){rear = NULL;}
    delete tmp;
    return x;
}

bool queue::isempty()
{
    return front == NULL;
}
