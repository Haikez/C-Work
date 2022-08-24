#include <iostream>
using namespace std;
#define maxSize 100
typedef struct ArcNode{
	int adjvex;
	int weight;
	ArcNode *nextarc;
}ArcNode;
typedef struct VNode{
	char data;
	ArcNode *firstarc;
}VNode;
typedef struct Agraph{
	VNode adjlist[maxSize];
	int n,e;
}Agraph;
void createGraph(Agraph *&G){
	char VName[]={'A','B','C','D','E'};
	G=new Agraph;
	G->n=5;
	G->e=7;
	for(int i=0;i<G->n;i++){
		G->adjlist[i].data=VName[i];
		G->adjlist[i].firstarc=NULL;	
	}
	ArcNode *a1=new ArcNode;
	ArcNode *b1=new ArcNode;
	ArcNode *c1=new ArcNode;
	a1->adjvex=1;
	b1->adjvex=3;
	c1->adjvex=4;
	G->adjlist[0].firstarc=a1;
	a1->nextarc=b1;
	b1->nextarc=c1;
	c1->nextarc=NULL;
	
	ArcNode *a2=new ArcNode;
	ArcNode *b2=new ArcNode;
	a2->adjvex=4;
	b2->adjvex=2;
	G->adjlist[1].firstarc=a2;
	a2->nextarc=b2;
	b2->nextarc=NULL;

	ArcNode *a3=new ArcNode;
	a3->adjvex=0;
	G->adjlist[2].firstarc=a3;
	a3->nextarc=NULL;

	ArcNode *a4=new ArcNode;
	a4->adjvex=2;
	a4->nextarc=NULL;
	G->adjlist[3].firstarc=a3;
	
	G->adjlist[4].firstarc=NULL;
}
