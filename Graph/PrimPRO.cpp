#include <iostream>
#include <cstdlib>
#define maxSize 20
#define INF 1000
using namespace std;

char VName[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
int weight[6][6] = {
    {0, 6, 1, 5, INF, INF},
    {6, 0, 5, INF, 3, INF},
    {1, 5, 0, 5, INF, 4},
    {5, INF, 5, 0, INF, 2},
    {INF, 3, 6, INF, 0, 6},
    {INF, INF, 4, 2, 6, 0}};

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
    g.n = 6;
    g.e = 10;
    for (int i = 0; i < g.n; i++)
    {
        g.vex[i].no = i;
        g.vex[i].data = VName[i];
        for (int j = 0; j < g.n; j++)
        {
            g.edgeW[i][j] = weight[i][j];
        }
    }
}
int p[maxSize][maxSize]={0};
void prim(MGraph g, int v0, int &sum)
{
    int lowcost[maxSize]; //当前生成树到图中其余各顶点的最小权值
    int vset[maxSize];    //标记数组，置1表示已经并入生成树
    int vlast[maxSize];    //用于标记上一个顶点
    int i, j, min, minj;
    for (i = 0; i < g.n; i++) //初始化
    {
        lowcost[i] = g.edgeW[v0][i];
        vset[i] = 0;
        vlast[i]=0;
    }
    vset[v0] = 1;
    sum = 0;

    for (i = 0; i < g.n - 1; i++)
    {
        min = INF;
        for (j = 0; j < g.n; j++) //找到与当前顶点相连的权值最小的边。
        {
            if (vset[j] == 0 && lowcost[j] < min)
            {
                min = lowcost[j];
                minj = j;
            }
        }
        cout<<g.vex[vlast[minj]].data<<"-->"<<g.vex[minj].data<<"\n";
        vset[minj] = 1; //将这条边并入到生成树中。
        sum += min;

        for (j = 0; j < g.n; j++) //更新lowcost数组。
        {
            if (vset[j] == 0 && g.edgeW[minj][j] < lowcost[j])
            {
                vlast[j]=minj;
                lowcost[j] = g.edgeW[minj][j];
            }
        }
    }
}

int main()
{
    MGraph g;
    createGraph(g);
    int sum = 0;
    prim(g, 0, sum);
    cout << "sum = " << sum <<"\n";
}