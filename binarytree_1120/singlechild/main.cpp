#include <iostream>
#include "single.h"
using namespace std;

int main()
{
    btree tree;
    tree.createTree();
    //tree.levelOrder();
    //cout << endl << "ɾ��null��";
    tree.delnull(tree.root);
    //cout << endl << "ɾ���ɹ�" << endl;
    //tree.levelOrder();
    //cout << endl << "���ӽ������";
    cout << tree.countSingle(tree.root);
}
