#include <iostream>
#include <vector>
using namespace std;
//打印[1,n]的全排列
vector<vector<int>> res;
vector<int> path;
void backtracking(int n, int startIndex)
{
    if (startIndex == n)
    {
        res.push_back(path);
        return;
    }
    for (int i = startIndex; i < n; i++)
    {
        swap(path[i], path[startIndex]);
        backtracking(n, startIndex + 1);
        swap(path[i], path[startIndex]);
    }
}
void perm(int n)
{
    for (int i = 1; i <= n; i++)
        path.push_back(i);
    backtracking(n, 0);
}
int main()
{
    perm(4);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}