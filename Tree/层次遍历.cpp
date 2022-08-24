#include <iostream>
#include"tree.h"
using namespace std;

void levelOrder(BTree T){
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
int main(){
	BTree T;
	createTree(T);
	levelOrder(T);
}
