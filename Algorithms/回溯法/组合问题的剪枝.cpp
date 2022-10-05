#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int> path, int n, int k, int startIndex)
    {
        if (path.size() == k)
        {
            res.push_back(path);
            return;
        }
        // i最多从n-(k-path.size())+1开始取值
        // 如果n=4,k=3。那么i最多从2开始取
        for (int i = startIndex; i < n-(k-path.size())+1; i++) //i < n-(k-path.size())+1这步是剪枝操作
        {
            path.push_back(i + 1);
            backtracking(path, n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        backtracking(path, n, k, 0);
        return res;
    }
};

int main()
{
    Solution test;
    test.combine(4, 2);
    for (int i = 0; i < test.res.size(); i++)
    {
        for (int j = 0; j < test.res[0].size(); j++)
        {
            cout << test.res[i][j] << " ";
        }
        cout << endl;
    }
}
