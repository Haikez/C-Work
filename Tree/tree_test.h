#include <iostream>
#include <cstdlib>
using namespace std;

typedef struct BTNode
{
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
} BTNode, *BiTree;

void createTree(BiTree &T)
{
	BTNode *a, *b, *c, *d, *e, *f, *g, *h, *i;
	T = (BTNode *)malloc(sizeof(BTNode));
	T->data = 1;
	a = (BTNode *)malloc(sizeof(BTNode));
	a->data = 2;
	b = (BTNode *)malloc(sizeof(BTNode));
	b->data = 3;
	c = (BTNode *)malloc(sizeof(BTNode));
	c->data = 4;
	d = (BTNode *)malloc(sizeof(BTNode));
	d->data = 5;
	e = (BTNode *)malloc(sizeof(BTNode));
	e->data = 6;
	f = (BTNode *)malloc(sizeof(BTNode));
	f->data = 7;
	g = (BTNode *)malloc(sizeof(BTNode));
	g->data = 8;
	h = (BTNode *)malloc(sizeof(BTNode));
	h->data = 9;
	i = (BTNode *)malloc(sizeof(BTNode));
	i->data = 10;
	T->lchild = a;
	T->rchild = b;
	a->lchild = c;
	a->rchild = NULL;
	b->lchild = d;
	b->rchild = e;
	c->lchild = NULL;
	c->rchild = f;
	d->lchild = g;
	d->rchild = h;
	e->lchild = NULL;
	e->rchild = i;
	f->lchild = NULL;
	f->rchild = NULL;
	g->lchild = NULL;
	g->rchild = NULL;
	h->lchild = NULL;
	h->rchild = NULL;
	i->lchild = NULL;
	i->rchild = NULL;
}
