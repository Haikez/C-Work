#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
bool Place(vector<string>&ans,int x,int y){
    int n=ans.size();
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ans[i][j]=='Q')
            {
                if (y==j||abs(x-i)==abs(y-j))
                {
                    return false;
                }
            }
            
        }
        
    }
    return true;
}
void backtracking(vector<vector<string>> &Queen,vector<string> &ans, int x){
    int n=ans.size();
    if (x==n)
    {
        Queen.push_back(ans);
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (Place(ans,x,i))
        {
            ans[x][i]='Q';
            backtracking(Queen,ans,x+1);
            ans[x][i]='.';
        }
    }
}
vector<vector<string>> solvebacktrackings(int n) {
    vector<vector<string>> Queen;
    vector<string> ans(n,string(n,'.'));
    backtracking(Queen,ans,0);
    return Queen;
}
int main(){
    vector<vector<string>> Queen = solvebacktrackings(8);
    for (int i = 0; i < Queen.size(); i++)
    {
        for (int j = 0; j < Queen[0].size(); j++)
        {
            cout<<Queen[i][j]<<endl;
        }
        cout<<endl;   
    }
}
