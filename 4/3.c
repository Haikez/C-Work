void i_sort(int arr[],int m,int n){
	for(int i=m;i<m+n;i++){
		int k=arr[m],j;
		for(j=i-1;j>=0&&arr[j]>k;j--){
			arr[j+1]=arr[j];
		}
		arr[j+1]=k;
	}
}
