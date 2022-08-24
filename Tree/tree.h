#include <iostream>
using namespace std;
#define maxSize 100
typedef struct BTNode
{
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
} BTNode, *BTree;

void createTree(BTree &T)
{
	BTNode *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;
	T = new BTNode;
	T->data = 1;
	a = new BTNode;
	a->data = 2;
	b = new BTNode;
	b->data = 3;
	c = new BTNode;
	c->data = 4;
	d = new BTNode;
	d->data = 5;
	e = new BTNode;
	e->data = 6;
	f = new BTNode;
	f->data = 7;
	g = new BTNode;
	g->data = 8;
	h = new BTNode;
	h->data = 9;
	i = new BTNode;
	i->data = 10;
	T->lchild = a;
	T->rchild = b;
	a->lchild = c;
	a->rchild = i;
	b->lchild = d;
	b->rchild = e;
	c->lchild = NULL;
	c->rchild = f;
	d->lchild = g;
	d->rchild = h;
	e->lchild = NULL;
	e->rchild = NULL;
	f->lchild = NULL;
	f->rchild = NULL;
	g->lchild = NULL;
	g->rchild = NULL;
	h->lchild = NULL;
	h->rchild = NULL;
	i->lchild = NULL;
	i->rchild = NULL;
}
void visit(BTNode *node){
	cout<<node->data<<" ";
}

