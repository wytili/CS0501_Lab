#include <iostream>
#include "lunch.h"

using namespace std;

int main()
{
    int num, stu_len = 0, lunch_len = 0, dissatisfy = 0, len;
    queue stu, lunch;
    while(cin >> num)
    {
        stu.enqueue(num);
        stu_len++;
        if(cin.get() == '\n'){break;}
    }
    while(cin >> num)
    {
        lunch.enqueue(num);
        lunch_len++;
        if(cin.get() == EOF){break;}
    }
    if(stu_len != lunch_len)
        {cout << "wrong number!";}
    else
        {
            len = lunch_len;
            for(int i = 0; i < len; i++)
            {   
                for(int j = 0; j < stu_len; j++)
                {
                    if(stu.gethead() == lunch.gethead())
                    {
                        stu.dequeue();
                        lunch.dequeue();
                        stu_len--;
                        lunch_len--;
                        dissatisfy = 0;
                        break;
                    }
                    else
                    {   
                        stu.enqueue(stu.dequeue());
                        dissatisfy++; 
                    }
                }
                if(dissatisfy == stu_len){cout << dissatisfy; break;}
                if(lunch.isempty()){cout << '0';break;}
            }
                
        }

}