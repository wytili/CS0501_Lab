#include <iostream>
#include "suffix.h"

using namespace std;

//tell operators
bool isoperator(char x)
{
    if(x == '+'||x == '-'||x == '*'||x == '/')
        return true;
    else
        return false;
}

int main()
{
    double left, right;
    double result;
    linkstack number;
    string suffix;
    int flag = 0;//whether the suffix is proper

    getline(cin, suffix);

    for(int i = 0; i < (int)suffix.size(); i++)
    {
        if(suffix[i] == ' '){continue;}//space
        else if (isdigit(suffix[i]))//number
        {   
            result = 0;
            while(i < (int)suffix.size() && suffix[i] != ' ' && isdigit(suffix[i]))
            {
                result = result * 10 + suffix[i] - '0';
                i++;
            }
            number.push(result);
        }
        else if(isoperator(suffix[i]))//operator
        {
            if(number.upper == NULL || number.upper -> next == NULL){flag = 1;break;}//less than 2 numbers being operated
            right = number.pop();
            left = number.pop();
            switch(suffix[i])
            {
                case '+' : 
                {
                    number.push(right + left);
                    break;
                }
                case '-' :
                {
                    number.push(left - right);
                    break;
                }
                case '*' :
                {
                    number.push(right * left);
                    break;
                }
                case '/' :
                {
                    if(right == 0)
                        {flag = 1;break;}//0 cannot be the divisor
                    else
                        {
                            number.push(left / right);
                            break;
                        }
                }
                default:break;
            }
        }
        else {flag = 1;}//improper char appears
    }
    if(number.isEmpty()||number.upper -> next != NULL){flag = 1;}//there are less or more than one number in the stack
    if(flag == 1){cout << "illegal";}
    else{cout << number.top();}
}
