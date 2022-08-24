#include<stdio.h>
int main(){
	int arr[][3]={
		{2,1,4},
		{3,2,1},
		{1,4,2}
	};
	printf("%d",arr[0][0]+arr[1][1]+arr[2][2]);
	return 0;
}
