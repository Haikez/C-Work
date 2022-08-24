#include<stdio.h>
int main(){
	int arr[]={2,4,6,7,8,10,12,55,65,89,0};//0是预留的插入空间
	//end代表最后一个元素的下标
	int end=sizeof(arr)/4-2;
	printf("请输入一个数:");
	int num=0;
	scanf("%d",&num);
	printf("插入前:\n");
	for(int i=0;i<=end;i++){
		printf("%d\t",arr[i]);
	}

	if(num>=arr[end])  arr[end+1]=num;
	else{
		for(int i=end+1;i>=0;i--){
			if(arr[i-1]>num){
				arr[i]=arr[i-1];
			}else{
				arr[i]=arr[i-1];
				arr[i-1]=num;
				break;
			}
		}
	}
	printf("\n插入后:\n");
	for(int i=0;i<=end+1;i++){
		printf("%d\t",arr[i]);
	}

	return 0;
}
