void fun(LNode * A,LNode *B){
	LNode *p=A->next;
	LNode *q=B->next;
	LNode *pre=A;
	while(p&&q){
		if(p->data<q->data){
			pre=p;
			p=p->next;
		}else if(p->data>q->data){
			q=q->next;
		}else{
			LNode *s=p;
			p=p->next;
			pre->next=p;
			free(s);
		}
	}
	
}
