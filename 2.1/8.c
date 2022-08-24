#include<stdio.h>
int main(){
	int arr[][5]={
		{1,3,8,5,6},
		{3,2,5,1,1},
		{4,2,7,1,7},
		{3,5,6,2,1}
	};
	int r=sizeof(arr)/sizeof(arr[0]);
	int c=sizeof(arr)/r/4;
	for(int i=0;i<r;i++){
		int k=0;
		for(int j=1;j<c;j++){
			if(arr[i][j]>arr[i][k]){
				k=j;
			}
		}
		//b判断是否是列最小
		int b=0;
		for(int a=0;a<r;a++){
			//如果列上存在比目标数小的数，跳出循环
			if(arr[a][k]<arr[i][k]){
				b=1;
				break;
			}
		}
		if(b==0){
			printf("%d\n",arr[i][k]);
		}
	}
	return 0;
}
