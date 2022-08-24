#include<stdio.h>
void change(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void fun(int (*p)[5]){
	for(int i=0;i<24;i++){
		for(int j=0;j<24-i;j++)
		{
			if(*(*p+j)>*(*p+j+1)){
				change(*p+j,*p+j+1);
			}
		}
	}
	change(*p+1,*p+4);
	change(*p+2,*p+20);
	change(*p+24,*p+12);
	change(*p+3,*p+24);

}
int main(){

	int arr[5][5]={
		{1,2,3,4,2},
		{2,3,4,5,6},
		{12,14,23,12,11},
		{5,7,8,0,10},
		{2,4,6,7,9}
	};
	int (*p)[5];
	p=arr;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("转换后:\n");
	fun(p);
   // for(int i=0;i<25;i++){
   // 	printf("%d ",*(*p+i));
   // }
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}

}
