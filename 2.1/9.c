#include<stdio.h>
int main(){
	int arr[15]={2,4,5,7,8,9,10,13,14,16,17,18,24,34,35};
	int input;
	for(int i=0;i<15;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n请输入要查询的数:");
	scanf("%d",&input);
	int left=0,right=14;
	while(left<=right){
		int mid=(left+right)>>1;
		if(arr[mid]==input){
			printf("位置在:%d",mid);
			return 0;
		}
		if(arr[mid]>input){
			right=mid-1;
		}else{
			left=mid+1;
		}
	}
	printf("无此数");
	return 0;
}
