#include<iostream>
#include<vector>
using namespace std;
/* 测试用例：
10 4
2 1
3 3
4 5
7 9

输出： 12
 */
int dp[305];
int m,n;
int w[35];
int c[35];
int main(){
    cin>>m>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>w[i]>>c[i];
    }
    for (int i = 1; i <=n; i++)
    {
        for (int j = m; j >=1; j--)//递推的时候从后往前推
        {
            if (j>=w[i])
            {
                dp[j]=max(dp[j],dp[j-w[i]]+c[i]);
            }
        }
    }
    cout<<dp[m];
    return 0;
}