#include <iostream>
#include <cstdlib>
#include"tree.h"
#define maxSize 100
using namespace std;
typedef struct lvlNode{
	BTNode *p;
	int level;
}lvlNode;
void levelOrder(BiTree T){
	int rear=0,front=0;
	BTNode *qu[100];
	BTNode *r;
	if(T!=NULL){
		rear = (rear + 1)%100;
		qu[rear] = T;
		while(rear !=front){
			front = (front + 1)%100;
			r=qu[front];
			visit(r);
			if(r->lchild){
				rear=(rear+1)%100;
				qu[rear]=r->lchild;
			}
			if(r->rchild){
				rear=(rear+1)%100;
				qu[rear]=r->rchild;
			}
		}
	}
}

void preOrder(BiTree T){
	if(!T) return;
	visit(T);
	preOrder(T->lchild);
	preOrder(T->rchild);
}
void inOrder(BiTree T){
	if(!T) return;
	inOrder(T->lchild);
	visit(T);
	inOrder(T->rchild);
}
void postOrder(BiTree T){
	if(!T) return;
	postOrder(T->lchild);
	postOrder(T->rchild);
	visit(T);
}
int count(BiTree T){
	if(!T) return 0;
	int l=count(T->lchild);
	int r=count(T->rchild);
	return l>r?l+1:r+1;
}
int numLeaf(BiTree T){
	if(!T) return 0;
	if(!T->lchild&&!T->rchild)
		return 1;
	return numLeaf(T->lchild)+numLeaf(T->rchild);
}
int treeWidth(BiTree T){
	lvlNode qu[maxSize];
	int rear=0,front=0;
	int width=1,curlvl=1,maxWith=1;
	lvlNode r;
	r.p=T;
	r.level=1;
	qu[++rear]=r;
	while(rear!=front){
		r=qu[++front];
		if(curlvl==r.level){
			curlvl++;
			width=0;
		}
		if(r.p->lchild){
			lvlNode temp;
			temp.p=r.p->lchild;
			temp.level=curlvl;
			width++;
			qu[++rear]=temp;
		}
		if(r.p->rchild){
			lvlNode temp;
			temp.p=r.p->rchild;
			temp.level=curlvl;
			width++;
			qu[++rear]=temp;
		}
		if(width>maxWith){
			maxWith=width;
		}
	}	
	return maxWith;
}
int treeWidth2(BiTree T){
	if(!T) return 0;
	int rear=0,front=0;
	lvlNode qu[maxSize];
	lvlNode r,s;
	r.p=T;
	r.level=1;
	qu[rear++]=r;
	while(rear!=front){
		r=qu[front++];
		if(r.p->lchild){
			s.p=r.p->lchild;
			s.level=r.level+1;
			qu[rear++]=s;
		}
		if(r.p->rchild){
			s.p=r.p->rchild;
			s.level=r.level+1;
			qu[rear++]=s;
		}
	}
	int max=1;
	int p=0,q=0,n=0;
	while(q<rear){
		if(qu[p].level==qu[q].level){
			++n;
			++q;
		}
		else{
			max=max>n?max:n;
			p=q;
			n=0;
		}
	}
	max=max>n?max:n;
	return max;
}
void link(BiTree T,BTNode *&head,BTNode *&tail){
	if(!T) return;
	if(!T->lchild&&!T->rchild){
		if(!head) head=tail=T;
		else{
			tail->rchild=T;
			tail=T;
		}
	}
	link(T->lchild,head,tail);
	link(T->rchild,head,tail);
}
int main(){
	BiTree T;
	createTree(T);
	//levelOrder(T);
	//printf("先序遍历:\n");
	//preOrder(T);
	//printf("\n");
	//printf("中序遍历:\n");
	//inOrder(T);
	//printf("\n");
	//printf("后序遍历:\n");
	//postOrder(T);
	//printf("\nNum=%d\n",count(T));
	//printf("LeafNum=%d",numLeaf(T));
	//printf("maxWith=%d",treeWidth2(T));
	BTNode *head=NULL;
	BTNode *tail=NULL;
	link(T,head,tail);
	while(head){
		printf("%d ",head->data);
		head=head->rchild;
	}
	
}
