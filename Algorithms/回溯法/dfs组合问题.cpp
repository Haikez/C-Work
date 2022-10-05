#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> res;
vector<int> path;
void dfs(int i,int n,int k){
    if(path.size()==k){
        res.push_back(path);
        return;
    }
    //如果超出可取的范围，直接返回
    if(i==n+1) return; 
    //如果取，将当前元素添加到path
    path.push_back(i);
    //进入下一层
    dfs(i+1,n,k);
    //返回上一层的时候弹出末尾的元素
    path.pop_back();
    //如果不取，直接进入下一层
    dfs(i+1,n,k);
}
vector<vector<int>> combine(int n, int k) {
    dfs(1,n,k);
    return res;
}
int main()
{
    combine(4, 2);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}