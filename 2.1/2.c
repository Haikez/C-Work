#include<stdio.h>
int main(){
	int arr[]={2,5,4,1,78,45,67,24,6,10};
	printf("排序前:\n");
	for(int i=0;i<sizeof(arr)/4;i++){
		printf("%d ",arr[i]);
	}

	for(int i=0;i<sizeof(arr)/4;i++){
		int k=i;
		for(int j=i;j<sizeof(arr)/4;j++){
			if(arr[j]<arr[k]){
				k=j;
			}
		}
		int tmp=arr[i];
		arr[i]=arr[k];
		arr[k]=tmp;
	}
	printf("\n排序后:\n");
	for(int i=0;i<sizeof(arr)/4;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
