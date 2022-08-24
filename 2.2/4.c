#include<stdio.h>
void T(int arr[][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<i;j++){
			int tmp=arr[i][j];
			arr[i][j]=arr[j][i];
			arr[j][i]=tmp;
		}
	}
}
int main(){
	int arr[][3]={
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}
	printf("转置后:\n");
	T(arr);
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%d\t",arr[i][j]);
		}
		printf("\n");
	}

}
