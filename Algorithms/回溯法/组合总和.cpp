#include <iostream>
#include <vector>
using namespace std;
/*
    输入：candidates = [2,3,6,7], target = 7
    输出：[[2,2,3],[7]]
    解释：
    2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
    7 也是一个候选， 7 = 7 。
    仅有这两种组合。
 */
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> selected;
    void backtracking(vector<int> &candidates,int n,int target,int startIndex)
    {
        if(target==0){
            res.push_back(selected);
            return;
        }else if (target<0)
        {
            return;
        }
        for (int i = startIndex; i < n ; i++)
        {
            selected.push_back(candidates[i]);
            backtracking(candidates,n,target-candidates[i],i);
            selected.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        backtracking(candidates,candidates.size(),target,0);
        return res;
    }
};
int main(){
    vector<int> candidates={2,3,6,7};
    Solution test;
    test.combinationSum(candidates,7);
    for (int i = 0; i < test.res.size(); i++)
    {
        for (int j = 0; j < test.res[0].size(); j++)
        {
            cout << test.res[i][j] << " ";
        }
        cout << endl;
    }
}