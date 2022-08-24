void partition(SqList &L){
	int target=L->data[0];
	int i=0,j=L->length-1;
	while(i<j){
		while(i<j&&L->data[j]>target)
			j--;
		L->data[i]=L->data[j];
		i++;
		while(i<j&&L->data[i]<target)
			i++;
		L->data[j]=L->data[i];
		j--;
	}
	L->data[i]=target;

}
