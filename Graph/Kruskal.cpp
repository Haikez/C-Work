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

typedef struct
{
    int a, b, w;
} Road;
Road road[maxSize];
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
    road[0].a = 0;
    road[0].b = 1;
    road[0].w = 6;
    road[1].a = 0;
    road[1].b = 2;
    road[1].w = 1;
    road[2].a = 0;
    road[2].b = 3;
    road[2].w = 5;
    road[3].a = 1;
    road[3].b = 2;
    road[3].w = 5;
    road[4].a = 1;
    road[4].b = 4;
    road[4].w = 3;
    road[5].a = 2;
    road[5].b = 3;
    road[5].w = 5;
    road[6].a = 2;
    road[6].b = 4;
    road[6].w = 6;
    road[7].a = 2;
    road[7].b = 5;
    road[7].w = 4;
    road[8].a = 4;
    road[8].b = 5;
    road[8].w = 6;
    road[9].a = 3;
    road[9].b = 5;
    road[9].w = 2;
}
int v[maxSize]; //并查集数组
void QSort(Road road[], int left, int right)
{ //快排
    int p = left, q = right;
    if (p < q)
    {
        Road key = road[p];
        while (p < q)
        {
            while (p < q && road[q].w >= key.w)
                --q;
            if (p < q)
            {
                road[p] = road[q];
                p++;
            }

            while (p < q && road[p].w <= key.w)
                ++p;
            if (p < q)
            {
                road[q] = road[p];
                q--;
            }
        }
        road[p] = key;
    }
    else
        return;
    QSort(road, left, p - 1);
    QSort(road, p + 1, right);
}
int getRoot(int a)
{
    while (a != v[a])
    {
        a = v[a];
    }
    return a;
}
void kruskal(MGraph g, int v0, int &sum)
{
    sum = 0;
    int i, a, b;
    //初始化并查集，使每个顶点的根都是自己
    for (i = 0; i < g.n; i++)
        v[i] = i;
    QSort(road, 0, g.e - 1);
    for (int i = 0; i < g.e; i++)
    {
        a = getRoot(road[i].a);
        b = getRoot(road[i].b);
        if (a != b) //判断a和b是否同根
        {
            v[a] = b;         //修改并查集，将a和b合并。
            sum += road[i].w; //将这条边的权值相加。
        }
    }
}
int main()
{
    MGraph g;
    createGraph(g);
    int sum;
    kruskal(g, 0, sum);
    cout << sum << " ";
}