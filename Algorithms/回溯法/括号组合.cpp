#include <iostream>
#include <vector>
#include<string>
using namespace std;
void backtracking(vector<string> &res,string &temp,int open,int close,int n){
    if (temp.size()==n*2)
    {
        res.push_back(temp);
        return;
    }
    if(open<n){
        temp.push_back('(');
        backtracking(res,temp,open+1,close,n);
        temp.pop_back();
    }
    if (open>close)
    {
        temp.push_back(')');
        backtracking(res,temp,open,close+1,n);
        temp.pop_back();
    }

}
int main(){
    vector<string> res;
    string temp;
    int n;
    cin>>n;
    backtracking(res,temp,0,0,n);
    for (int i = 0; i < res.size(); i++)
    {
        cout<<res[i]<<endl;
    }
    
}