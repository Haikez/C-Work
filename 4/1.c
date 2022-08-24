#include<stdio.h>
void merge(LNode* A,LNode* B,LNode* &C){
	LNode *C=A;
	C->next=NULL;
	LNode *r=C;
	LNode *p=A->next;
	LNode *q=B->next;
	while(p&&q){
		if(p->value<q->value){
			r->next=p;
			r=r->next;
			p=p->next;
		}else{
			r->next=q;
			r=r->next;
			q=q->next;
		}
	}
	if(p) r->next=p;
	if(q) r->next=q;
}
