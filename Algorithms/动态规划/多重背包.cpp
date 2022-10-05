#include<iostream>
#include<vector>
#define maxSize 15000
using namespace std;

/* 
    用二进制优化多重背包，将当前物品数划分为1 2 4 8 ....每份乘上物品价值和重量，记录在价值和重量中
 */
int dp[maxSize];
int w[maxSize];
int v[maxSize];
int main(){
    int n,m;
    cin>>n>>m;
    int t=1;
    for (int i = 1; i <= n; i++)
    {
        int ww,vv,s;
        cin>>ww>>vv>>s;
        for (int k = 1; k<= s; k*=2)
        {
            w[t]=k*ww;
            v[t]=k*vv;
            t++;
            s-=k;
        }
        if(s>0){
            w[t]=s*ww;
            v[t]=s*vv;
            t++;
        }
    }
    for (int i = 1; i <=t; i++)
    {
        for (int j = m; j >=1; j--)//递推的时候从后往前推
        {
            if (j>=w[i])
            {
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
    }
    cout<<dp[m];
    return 0;
}