#include<stdio.h>
int main(){
	int arr[]={8,6,5,4,1};
	int len=sizeof(arr)/4;
	printf("逆序前:\n");
	for(int i=0;i<len;i++){
		printf("%d\t",arr[i]);
	}

	for(int i=0;i<len/2;i++){
		int tmp=arr[i];
		arr[i]=arr[len-i-1];
		arr[len-i-1]=tmp;
	}
	printf("\n逆序后:\n");
	for(int i=0;i<len;i++){
		printf("%d\t",arr[i]);
	}
}
