#include<stdio.h>
int main(){
	char str[100];
	gets(str);
	int n=0;
	while(str[n]!='\0'){
		n++;
	}
	printf("%d",n);
}
