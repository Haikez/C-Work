#include<stdio.h>
void fun(int *arr,int len){
	for(int i=0;i<len>>1;i++){
		int tmp=arr[i];
		arr[i]=arr[len-i-1];
		arr[len-i-1]=tmp;
	}
	return;
}
int main(){

	int a[]={3,7,9,11,0,6,7,5,4,2};
	fun(a,10);
	for(int i=0;i<10;i++){
		printf("%d\t",a[i]);
	}
	return 0;
}
