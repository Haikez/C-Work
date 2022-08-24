int findK(LNode *L,int k){
	LNode *p=L,*q=L;
	for(int i=0;i<k;i++){
		if(q->next){
			q=q->next;
		}else break;
	}
	while(q->next){
		p=p->next;
		q=q->next;
	}
	if(p!=L){
		printf("%d",p->next->data);
		return 1;
	}else return 0;
	
}
