#include<stdio.h>
#include "tree.h"
#define maxSize 100

BTNode *qu[maxSize];
int front=0;
void preOrder(BiTree T){
	if(!T) return;
	qu[++front]=T;
	//visit(T);
	preOrder(T->lchild);
	preOrder(T->rchild);
}
int main(){
	BiTree T;
	createTree(T);
	BTNode r;
	preOrder(T);
	for(int i=1;i<=front;i++){
		r=*qu[i];
		printf("%d ",r.data);
	}
}
