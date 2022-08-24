#include<stdio.h>
void swap(int arr[],int a,int b){
	for(int i=a,j=b;i<j;i++,j--){
		int tmp=arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
	}
}
void fun(int arr[],int n,int m){
	swap(arr,0,n-m-1);
	swap(arr,n-m,n-1);
	swap(arr,0,n-1);

}
int main(){
	int n,m;
	printf("n m:\n");
	scanf("%d %d",&n,&m);
	int arr[100];
	for(int i=0;i<n;i++){
		if(i==n-1){
			scanf("%d",&arr[i]);
		}else{
			scanf("%d ",&arr[i]);
		}
	}
	fun(arr,n,m);
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}

}
