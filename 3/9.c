#include<stdio.h>
void fun(int (*p)[3]){
	int tmp,i,j;
	for(i = 0;i<3;i++){
		for(j=0;j<i;j++){
			tmp=*(*(p+i)+j);
			*(*(p+i)+j)=*(*(p+j)+i);
			*(*(p+j)+i)=tmp;
		}
	}

}
int main(){
	int arr[3][3]={
		{1,2,3},{4,5,6},{7,8,9}
	};
	int (*p)[3];
	p=arr;
	fun(p);
   // for(int i=0;i<9;i++){
   // 	printf("%d ",*(*p+i));
   // }
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}
