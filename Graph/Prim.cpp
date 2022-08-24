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
void Prim(MGraph g,int v0,int &sum){
    int lowcost[maxSize];
    int visit[maxSize];
    int minj;
    for (int i = 0; i < g.n; i++)
    {
        lowcost[i]=g.edgeW[v0][i];
        visit[i]=0;
    }
    visit[v0]=1;
    sum=0;
    for (int  i = 0; i < g.n-1; i++)
    {
        int min=INF;
        for (int  j = 0; j < g.n; j++)
        {
            if (visit[j]==0&&lowcost[j]<min)
            {
                min=lowcost[j];
                minj=j;
            }
            
        }
        sum+=lowcost[minj];
        visit[minj]=1;
        for (int j = 0; j < g.n; j++)
        {
            if(visit[j]==0&&lowcost[j]>g.edgeW[minj][j]){
                lowcost[j]=g.edgeW[minj][j];
            }
        }
    }
    
}
int main(){
    MGraph g;
    createGraph(g);
    int sum=0;
    Prim(g,0,sum);
    cout<<sum;
}