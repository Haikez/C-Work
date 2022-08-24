void delElem(LNode *L){
	LNode *p=L->next;
	LNode *q=p->next;
	while(p->next){
		if(p->data==p->next->data){
			p->next=q->next;
			free(q);
		}else{
			p=p->next;
		}
	}
}
