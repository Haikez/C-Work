void split(LNode *A,LNode *&B){
	LNode *B = (LNode *)malloc(sizeof(LNode));
	B->next=NULL;
	LNode *p=A,*q=B;
	while(p->next){
		if(p->next->data&1){
			p=p->next;
		}else{
			q->next=p->next;
			q=q->next;
			p->next=q->next;
			q->next=NULL;
		}
	}
}
