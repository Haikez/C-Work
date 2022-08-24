#include <iostream>
#include <cstdlib>
#define maxSize 20
#define INF 1000
using namespace std;
/*
  设有两个顶点集合S和T，集合S中存放图中已经找到最短路径的顶点，集合T存放图中剩余顶点。
初始状态时，集合S中只包含源点V0，然后不断的从集合T中选取到顶点V0路径长度最短的顶点Vu并入
到集合S中。集合S每并入一个新的顶点Vu，都要修正顶点V0到集合T中顶点的最短路径长度值。不断
重复此过程，直到T的顶点全部并入到S中为止。
*/
char VName[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
int weight[7][7] = {0, 4, 6, 6, INF, INF, INF,
                    4, 0, 1, INF, 7, INF, INF,
                    6, 1, 0, 2, 6, 4, INF,
                    6, INF, 2, 0, INF, 5, INF,
                    INF, 7, 6, INF, 0, 1, 6,
                    INF, INF, 4, 5, 1, 0, 8,
                    INF, INF, INF, INF, 6, 8, 0};

typedef struct
{
    int no;
    char data;
} VNode;

typedef struct
{
    int edgeW[maxSize][maxSize];
    int n, e;
    VNode vex[maxSize];
} MGraph;

void createGraph(MGraph &g)
{
    g.e = 12;
    g.n = 7;

    for (int i = 0; i < g.n; ++i)
    {
        g.vex[i].data = VName[i];
        g.vex[i].no = i;
    }

    for (int i = 0; i < g.n; ++i)
        for (int j = 0; j < g.n; ++j)
            g.edgeW[i][j] = weight[i][j];
}

void dijkstra(MGraph g, int v0,int dist[],int path[])
{
    int set[maxSize];
    for (int i = 0; i < g.n; i++)
    {
        dist[i] = g.edgeW[v0][i];
        path[i] = -1;
        set[i] = 0;
    }
    set[v0] = 1;
    
    for (int i = 1; i < g.n; i++)
    {
        int min = INF, k = 0;
        for (int i = 1; i < g.n; i++)
        {
            if (!set[i] && dist[i] < min)
            {
                min = dist[i];
                k = i;
            }
        }
        set[k] = 1;
        for (int j = 0; j < g.n; j++)
        {
            if (!set[j] && (dist[k] + g.edgeW[k][j]) < dist[j])
            {
                dist[j] = dist[k] + g.edgeW[k][j];
                path[j] = k;
            }
        }
    }

    
}
int main()
{
    MGraph g;
    int path[maxSize];
    int dist[maxSize];
    createGraph(g);
    dijkstra(g, 0,dist,path);
    int a = 5;
    int stack[maxSize];
    int top = -1;
    for (int i = 0; i < g.n; i++)
    {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < g.n; i++)
    {
        cout<<path[i]<<" ";
    }
    cout<<endl;
    while (path[a] != -1)
    {
        stack[++top] = path[a];
        a = path[a];
    }
    while(top!=-1){
        cout<<stack[top--]<<" ";
    }
}