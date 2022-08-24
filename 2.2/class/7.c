#include<stdio.h>
void fun(int *arr,int n){
	for(int i=0;i<n;i++){
		int k=i;
		for(int j=i+1;j<10;j++){
			if(arr[j]<arr[k]){
				k=j;
			}
		}
		int tmp=arr[i];
		arr[i]=arr[k];
		arr[k]=tmp;
	}
	
}
