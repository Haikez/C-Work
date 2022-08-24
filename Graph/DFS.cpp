#include<iostream>
#include"ADJList.h"
using namespace std;
int visited[maxSize]={0};//用visited数组标记是否被访问过
void DFS(Agraph *G,int v){
    visited[v]=1;    //访问顶点
    cout << G->adjlist[v].data<<" ";  
    ArcNode *s = G->adjlist[v].firstarc; //s指向第一条边
    while (s) //当s不为空
    {
        if(!visited[s->adjvex]){    
           DFS(G,s->adjvex);    //如果没被访问过则递归访问边结点
        }
        s=s->nextarc;  //s指向下一条边
    }
    
}
int main(){
    Agraph *G;
    createGraph(G);
    DFS(G,0);
}