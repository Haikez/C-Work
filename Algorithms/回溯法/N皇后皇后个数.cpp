#include <iostream>
#include <vector>
using namespace std;
bool Place(int pos[],int x,int y){
    //为了判断是否会同列，所以从0行挨个往下找，直到x
    //(i,pos[i])为棋盘。(x,y)是当前坐标
    for (int i = 0; i < x; i++)
    {
        if (pos[i]==y||abs(x-i)==abs(pos[i]-y))
        {
            return false;
        }
    }
    return true;
}
void backtracking(int pos[],int n,int x,int &res){
    if (x==n)
    {
        res++;
        return;
    }
    //遍历所有列
    for (int i = 0; i < n; i++)
    {
        //如果当前列能放
        if (Place(pos,x,i))
        {
            pos[x]=i;
            backtracking(pos,n,x+1,res);
        }
    }
}
int NQueen(int n){
    int res=0;
    int *pos=(int *)malloc(sizeof(int)*n);
    memset(pos,0,n);
    backtracking(pos,n,0,res);
    return res;
}
int main(){
    int n=8;
    cout<<NQueen(n);
}