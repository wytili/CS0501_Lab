#include <iostream>
#include "subtree.h"
using namespace std;

int main()
{
    btree tree;
    tree.createTree();
    tree.deleteLeaves(tree.root, "0");
    string str = tree.levelOrder();
    while(str[str.size() - 1] == 'n' || str[str.size() - 1] == 'u' || str[str.size() - 1] == 'l' || str[str.size() - 1] == ' ')
    {str.pop_back();}//为了让输出到最后一个非NULL结点就结束, 把字符串尾的null都删除
    cout << str;
}

