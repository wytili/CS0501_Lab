#include <iostream>
#include "single.h"
using namespace std;

int main()
{
    btree tree;
    tree.createTree();
    //tree.levelOrder();
    //cout << endl << "删除null中";
    tree.delnull(tree.root);
    //cout << endl << "删除成功" << endl;
    //tree.levelOrder();
    //cout << endl << "单子结点数：";
    cout << tree.countSingle(tree.root);
}
