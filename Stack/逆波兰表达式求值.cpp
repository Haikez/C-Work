/* 根据 逆波兰表示法，求表达式的值。

有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

注意 两个整数之间的除法只保留整数部分。

可以保证给定的逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

示例 1：

输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
long calculate(long a,long b,string sign){
    if (sign=="+")
    {
        return a+b;
    }
    if (sign=="-")
    {
        return a-b;
    }
    if (sign=="*")
    {
        return a*b;
    }
    if (sign=="/"&&b!=0)
    {
        return a/b;
    }
    return 0;
    
}
long evalRPN(vector<string>& tokens) {
    long n=tokens.size();
    vector<long> stack(n);
    long top=-1;
    long sum=0;
    for (long i = 0; i < n; i++)
    {
        if (tokens[i]!="+"&&tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/")
        {
            long temp=0;
            long flag=1;
            for (long j = 0; j < tokens[i].size(); j++)
            {
                if (tokens[i][j]=='-')
                {
                    flag=-1;
                    continue;
                }
                temp*=10;
                temp+=tokens[i][j]-'0';
            }
            temp*=flag;
            flag=1;
            stack[++top]=temp;
        }else if (top>=1)
        {
            long s2=stack[top--];
            long s1=stack[top--];
            long temp=calculate(s1,s2,tokens[i]);
            stack[++top]=temp;
        }
        if (top==0)
        {
            sum=stack[top];
        }        
    }
    return sum;
}
int main(){
    vector<string> tokens={"-128","-128","*","-128","*","-128","*","8","*","-1","*"};
    cout<<evalRPN(tokens);
}