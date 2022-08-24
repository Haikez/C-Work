#include<iostream>
#include"ADJList.h"
using namespace std;
int visited[maxSize]={0};
void DFS(Agraph *G,int v){
    visited[v]=1;
    cout << G->adjlist[v].data<< " ";
    ArcNode *s=G->adjlist[v].firstarc;
    while (s)
    {
        if(!visited[s->adjvex]){
            DFS(G,s->adjvex);
        }
        s=s->nextarc;
    }
    
}
void BFS(Agraph *G,int v){
    int queue[maxSize]={0},front=0,rear=0;
    visited[v]=1;
    cout<<G->adjlist[v].data<<" ";
    queue[rear]=v;
    rear=(rear+1)%maxSize;
    int p;
    ArcNode *s;
    while (front!=rear)
    {
        p=queue[front];
        front=(front+1)%maxSize;
        s=G->adjlist[p].firstarc;
        while (s)
        {
            if(!visited[s->adjvex]){
                visited[s->adjvex]=1;
                cout<<G->adjlist[s->adjvex].data<<" ";
                queue[rear]=s->adjvex;
                rear=(rear+1)%maxSize;
            }
            s=s->nextarc;
        }
        
    }
    
}
int main(){
    Agraph *G;
    createGraph(G);
    DFS(G,0);
}