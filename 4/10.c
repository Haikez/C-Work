void printList(LNode *p){
	if(p==NULL) return;
	printList(p->next);
	printf("%d",p->data);
}
