#include<iostream>
#include<vector>
using namespace std;
int dp[35][205]={0};
int w[35]={0},c[35]={0};
/* 测试用例：
10 4
2 1
3 3
4 5
7 9

输出： 12
 */
int main(){
    int m,n;
    cin>>m>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>w[i]>>c[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            //如果能放下当前物品
            if (j>=w[i])
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+c[i]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][m];
    
    
}