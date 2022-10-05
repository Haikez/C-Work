#include<iostream>
#include<string>
#include<vector>
using namespace std;
string longStr(string str1,string str2){
    vector<vector<int> >dp(str1.size()+1,vector<int>(str2.size()+1,0));
    for (int i = 0; i < str1.size(); i++)
    {
        dp[i][0]=0;
    }
    for (int j = 0; j < str2.size(); j++)
    {
        dp[0][j]=0;
    }
    int p=0,max=0;
    for (int i = 1; i <= str1.size(); i++)
    {
        for (int j = 1; j <= str2.size(); j++)
        {
            if (str1[i-1]==str2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                if (max<dp[i][j])
                {
                   max=dp[i][j];
                    p=i-1; 
                }
            }else{
                dp[i][j]=0;
            }
        }
    }
    cout<<max<<endl;
    return str1.substr(p-max+1,max);
}
int main(){
    string str1="abcdefgsddafdj;dh;flkdfa";
    string str2="shdabcdlkdfjald'fkh;jefgsdg";
    cout<<longStr(str1,str2);
}