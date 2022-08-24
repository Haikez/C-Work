int compare(float A[],int m,float B[],int n){
	int i=0;
	while(i<m&&i<n){
		if(fabs(A[i]-B[i])<min){
			i++;
		}
		else break;
	}
	if(i==m&&i==n){
		return 0;
	}
	else if((i>=m&&i<n)||(i<n&&A[i]<B[i])){
		return -1;
	}
	else return 1;
}
