#include<iostream>
#include<string>
#include<vector>
#define maxSize 100
using namespace std;
int minpath(vector<vector<int> >matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int> > dp(maxSize,vector<int>(maxSize));
    dp[0][0]=matrix[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i-1][0]+matrix[i][0];
    }
    for (int j = 0; j < m; j++)
    {
        dp[0][j]=dp[0][j-1]+matrix[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+matrix[i][j-1];
        }
    }
    return dp[n-1][m-1];
}