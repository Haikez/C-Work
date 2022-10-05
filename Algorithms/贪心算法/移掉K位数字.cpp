/*
给你一个以字符串表示的非负整数 num 和一个整数 k ，移除这个数中的 k 位数字，使得剩下的数字最小。请你以字符串形式返回这个最小的数字。

 
示例 1 ：
输入：num = "1432219", k = 3
输出："1219"
解释：移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219 。
*/
#include <iostream>
#include <vector>
using namespace std;
char *removeKdigits(char *num, int k)
{
    int len = strlen(num);
    if(len==k) return "0";
    for (int i = 0; i < k; i++)
    {
        int j;
        for (j = 0; j < len - 1; j++)
        {
            if (num[j] > num[j + 1])
            {
                while (j + 1 < len)
                {
                    num[j] = num[j + 1];
                    j++;
                }
                num[j] = '\0';
                len--;
                break;
            }
        }
        if (j == len - 1)
        {
            num[j] = '\0';
            len--;
        }
    }
    if (len > 1)
    {
        int i = 0, j = 0;
        while (num[i] == '0' && i < len-1)
            ++i;
        for (j = 0; i < len; i++)
        {
            num[j++] = num[i];
        }
        num[j] = '\0';
    }
    return num;
}
int main()
{
    char num[] = "1432219";
    cout << removeKdigits(num, 3) << endl;
}