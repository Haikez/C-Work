#include<stdio.h>
#include<string.h>
int main(){
	char s1[100],s2[100];
	gets(s1);
	int m,n=0;
	scanf("%d",&m);
	while(s1[n]!='\0') n++;
	strcpy(s2,s1+m-1);
	printf("%s",s2);
}
