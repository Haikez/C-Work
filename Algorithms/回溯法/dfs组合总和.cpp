#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> res;
vector<int> path;
void dfs(vector<int> &nums,int i,int target){
    if(target==0){
        res.push_back(path);
        return;
    }
    if (target<0||i==nums.size())
    {
       return;
    }
    //如果取当前的元素
    path.push_back(nums[i]);
    dfs(nums,i,target-nums[i]);
    path.pop_back();
    //如果不取
    dfs(nums,i+1,target);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    dfs(candidates,0,target);
    return res;
}
int main(){
    vector<int> candidates={2,3,6,7};
    combinationSum(candidates,7);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}