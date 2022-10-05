#include<iostream>
#include<string>
#include<vector>
using namespace std;
int longestCommonSubsequence(string text1, string text2) {
    int n1=text1.size();
    int n2=text2.size();
    //dp[i][j]表示text1长度为i和text2长度为j的最长公共子序列长度
    vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (text1[i-1]==text2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }else{
                dp[i][j]=max(dp[i-1][j],dp[j-1][i]);
            }
        }
    }
    return dp[n1][n2];
}
int main(){
    string text1= "A";
    string text2="";
cout<<longestCommonSubsequence(text1,text2);
}