#include<stdio.h>
void fun(int n){
	if(n==0){
		return;
	}
	fun(n/10);
	printf("%c",n%10+'0');
}
int main(){
	int n;
	scanf("%d",&n);
	fun(n);
}
