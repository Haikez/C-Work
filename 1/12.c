#include<stdio.h>
int main(){
	int num =1;
	for(int i=0;i<9;i++){
		num=(num+1)*2;
	}
	printf("第一天一共有%d个桃子\n",num);
	return 0;
}
