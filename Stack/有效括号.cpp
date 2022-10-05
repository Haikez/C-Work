#include<iostream>
#include<vector>
using namespace std;
/* 
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
 */

bool isValid(string s) {
    if(s.size()%2) return false;
    char *stack=(char *)malloc(sizeof(char)*s.size());
    int top=-1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='(')
        {
            stack[++top]=')';
        }
        else if (s[i]=='[')
        {
            stack[++top]=']';
        }
        else if (s[i]=='{')
        {
            stack[++top]='}';
        }
        else{
            if (top==-1||s[i]!=stack[top])
            {
                return false;
            }else{
                top--;
            }
        }
    }
    if (top!=-1)
    {
        return false;
    }
    return true;
}
