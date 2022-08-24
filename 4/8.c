void reverse(LNode *L){
	LNode *p=L->next;
	L->next=NULL;
	LNode *s;
	while(p){
		s=p;
		p=p->next;
		s->next=L->next;
		L->next=s;
	}
}
