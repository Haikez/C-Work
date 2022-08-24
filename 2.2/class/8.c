#include<stdio.h>
void fun(int *arr,int a,int b){
   // for(;a<b;a++,b--){
   // 	int tmp=arr[a];
   // 	arr[a]=arr[b];
   // 	arr[b]=tmp;
   // }
	
	int c=a;
	for(a;a<a+(b-a+1)>>1;a++){
		int tmp=arr[a]; 
		arr[a]=arr[b-a+c];
		arr[b-a+c]=tmp;
	}
}
int main(){
	int m,n;
	int arr[]={1,2,3,4,5,6,7,8,9,0};
	scanf("%d %d",&m,&n);
	fun(arr,0,m-1);
	fun(arr,m,n-1);
	fun(arr,0,n-1);
	for(int i=0;i<10;i++){
		printf("%d\t",arr[i]);
	}

}
