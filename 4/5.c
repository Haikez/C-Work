void delElem(SqList &L,int i,int j){
	int len=j-i-1;
	for(int k=i;k<L->length-len;k++){
		L->data[k]=L->data[k+len];
	}
	L->length-=len;
}
