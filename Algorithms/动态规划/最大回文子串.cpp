#include<iostream>
#include<vector>
#include<string>
using namespace std;
string longestPalindrome(string s){
    int n=s.size();
    //dp[i][j]表示字符串s下标从i到j是否是回文串，如果是dp[i][j]=1，否则dp[i][j]=0;
    vector<vector<int>>dp(n,vector<int>(n,0));
    for (int i = 0; i < n; i++)
        dp[i][i]=1;
    int p=0,max=1;
    //r表示子串长度
    for (int r = 2; r <=n ; r++)
    {
        for (int i = 0; i <= n-r+1 ; i++)
        {
            int j=i+r-1;
            if (s[i]==s[j]) 
            {
                if (r==2)
                {
                    dp[i][j]=1;
                }else{
                    dp[i][j]=dp[i+1][j-1];
                }
                if (dp[i][j])
                {
                    max=r;
                    p=i;
                }
            }
        }
    }
    return s.substr(p,max);
}
int main(){
    string str="abbcbbbbc,hhhhhhhh,djia";
    cout<<longestPalindrome(str);
}

