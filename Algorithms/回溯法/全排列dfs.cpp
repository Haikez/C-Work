#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> res;
vector<int> path;
int visited[100] = {0};
//打印[1,n]的全排列
void dfs(int n, int step)
{
    if (path.size() == n)
    {
        res.push_back(path);
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            path.push_back(i);
            visited[i] = 1;
            dfs(n, i + 1);
            visited[i] = 0;
            path.pop_back();
        }
    }
}
int main()
{
    dfs(4, 1);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}