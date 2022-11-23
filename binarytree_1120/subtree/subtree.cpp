#include <iostream>
#include "subtree.h"

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

string btree::levelOrder()
{
    queue q;
    Node *tmp;
    string output;

    //cout << "LevelOrder:" << endl;
    q.enqueue(root);

    while(!q.isempty())
    {
        tmp = q.dequeue();
        output += tmp->data;
        output += " ";
        if (tmp->left != NULL)
            q.enqueue(tmp->left);
        if(tmp->right != NULL)
            q.enqueue(tmp->right);
    }
    return output;
}

void btree::createTree()
{
    queue que;
    Node *tmp;
    string x;
    cin >> x;
    root = new Node(x, size);
    size++;
    if(cin.get() == '\n'){return;}//change '\n' to EOF in educoder
    que.enqueue(root);
    while(cin >> x)
    {
        tmp = que.dequeue();
        size++;
        que.enqueue(tmp -> left = new Node(x, size));
        if(cin.get() == '\n'){break;}
        cin >> x;
        size++;
        que.enqueue(tmp -> right = new Node(x, size));
        if(cin.get() == '\n'){break;}
    }
}

//�������,���м�Ϊ0��Ҷ�ӽڵ���Ϊnull,���Ϊ0��Ҷ�ӽ��ɾ��
btree::Node* btree::deleteLeaves(btree::Node* x, string y)
{
    if (x == NULL)return x;
    x -> right = deleteLeaves(x -> right, y);
    x -> left = deleteLeaves(x -> left, y);
    if ((x -> data == y || x -> data == "null") && (x -> left == NULL || x -> left -> data == "null") && (x -> right == NULL || x -> right -> data == "null")) 
    {
        if(x == root)cout << "null";//ɾ�����ڵ�
        if(x -> number == size){delete x; x= NULL; size--; return x;}//ɾ�����һ��Ҷ�ӽڵ�
        else{
                x -> data = "null";
                return x;
            }
    };
    return x;
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
