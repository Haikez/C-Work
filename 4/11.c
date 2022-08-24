int isEqual(LNode *A,LNode *B){
	LNode *p=A->next;
	LNode *q=B->next;
	while(p&&q){
		if(p->data!=q->data){
			return 0;
		}
		p=p->next;
		q=q->next;
	}
	if(p||q){
		return 0;
	}
	return 1;
}
