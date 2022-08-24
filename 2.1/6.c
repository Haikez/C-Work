#include<stdio.h>
int main(){
	int arr[10][10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			arr[i][j]=0;
		}
	}
	arr[0][0]=1;
	for(int i=1;i<10;i++){
		for(int j=0;j<=i;j++){
			if(j==0){
				arr[i][j]=1;
				continue;
			}
			arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
		}
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<=i;j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
