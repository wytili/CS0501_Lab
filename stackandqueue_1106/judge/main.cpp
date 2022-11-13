#include <iostream>
#include "judge.h"

using namespace std;

int main()
{
    int s;
    cin >> s;
    for(int i = 0; i < s; i++)
    {
        int z, qflag = 1, sflag = 1;
        cin >> z;
        queue que;
        stack sta;
        for(int j = 0; j < z; j++)
        {
            int oper, num;
            cin >> oper >> num;
            if(oper == 1)
            {    
                que.enqueue(num);
                sta.push(num);
            }
            if(oper == 2)
            {   
                if(que.dequeue() != num){qflag = 0;}
                if(sta.pop() != num){sflag = 0;}
            }
        }
        que.~queue();
        sta.~stack();
        if(sflag == 1 && qflag == 1){cout << "Both" << endl;}
        if(sflag == 0 && qflag == 1){cout << "Queue" << endl;}
        if(sflag == 1 && qflag == 0){cout << "Stack" << endl;}
        if(sflag == 0 && qflag == 0){cout << "Error" << endl;}

    }

}