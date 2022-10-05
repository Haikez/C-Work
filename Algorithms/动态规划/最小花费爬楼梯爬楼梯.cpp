#include<iostream>
#include<vector>
using namespace std;

int step(vector<int> cost){
    int n=cost.size();
    vector<int> dp(n+1,0);
    //dp[i]相当于跳到数组i这个位置所花费的力气
    dp[0]=0;
    dp[1]=0;
    for (int i = 2; i <=n; i++)
    {
        dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
    }
    //因为要求的是跳出数组所花费的全部力气，故相当于跳到第n+1个台阶，所以返回dp[n]
    return dp[n];
}
int main(){
    vector<int> nums={2,5,20};
    cout<<step(nums);
}
