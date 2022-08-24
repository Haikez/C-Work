#include<stdio.h>
#include<stdbool.h>
bool fun(int n){
	for(int i=2;i<n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main(){
	int n;
	printf("请输入一个数:");
	scanf("%d",&n);
	const char *p;
	if(fun(n)) p="true";
	else p="false";
	printf("是否为素数:%s",p);
	return 0;
}
