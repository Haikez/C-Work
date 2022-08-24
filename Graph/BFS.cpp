#include <iostream>
#include "ADJList.h"
using namespace std;
int visited[maxSize] = {0};
void BFS(Agraph *G, int v)
{
    //创建队列，访问顶点，访问完顶点入队。
    int queue[maxSize], front = 0, rear = 0;
    visited[v] = 1;
    cout << G->adjlist[v].data << " ";
    queue[rear++] = v;
    ArcNode *s;
    int p;
    while (front != rear)
    {
        //当队不为空，队头结点出队列。s指向队头结点的第一条边。（因为队头结点被访问过了，所以指向第一条边）。
        p = queue[front++];
        s = G->adjlist[p].firstarc;
        //当s非空
        while (s)
        {
            //如果s未被访问，访问s并入队。
            if (!visited[s->adjvex])
            {
                visited[s->adjvex] = 1;
                cout << G->adjlist[s->adjvex].data << " ";
                queue[rear++] = s->adjvex;
            }
            //s指向下一条边
            s = s->nextarc;
        }
    }
}
int main()
{
    Agraph *G;
    createGraph(G);
    BFS(G, 0);
}