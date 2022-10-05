/* 
给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。

 
示例 1 ：
输入：num = "1432219", k = 3
输出："1219"
解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 。 
*/
#include<iostream>
#include<string>
using namespace std;

/* 
    思路：
    只要后一个数比前一个数大，就移掉后一个数
 */
string removeKdigits(string num, int k) {
    int i = 0;
    if (k==num.size())
        return "0";
    //删除k位
    for (; i < num.size()-1&&k>0; i++)
    {
        if (num[i]>num[i+1])
        {
            num.erase(i,1);
            if (i==0)
            {
                i-=1;
            }else
                i-=2;
            k--;
        }
    }
    //如果没删到k位，则从结尾依次删
    while (k)
    {
       num.erase(i,1);
       k--;i--;
    }
    //删除前导0
    while (num[0]=='0'&&num.size()>1)
        num.erase(0,1);
    return num;
}
int main(){
    string num = "10001";
    cout<<removeKdigits(num,4)<<endl;
}