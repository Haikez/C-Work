#include <iostream>
#include <vector>
using namespace std;
int dfs(vector<vector<int>>&A, int m,int n,int x,int y){
    if (x<0||y<0||x==m||y==n||A[x][y]==0)
    {
        return 0;
    }
    A[x][y]=0;
    int ans=1;
    ans+=dfs(A, m,n,x+1,y);
    ans+=dfs(A, m,n,x-1,y);
    ans+=dfs(A, m,n,x,y+1);
    ans+=dfs(A, m,n,x,y-1);
    return ans;
}
int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    int ans=0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j]==1)
                ans=max(ans,dfs(grid,m,n,i,j));
        }
    }
    return ans;
}
