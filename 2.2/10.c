#include<stdio.h>
void fun(char *s){
	char *c1=s;
	char *c2=c1;
	char *c3=c1;int max=0;
	while(*c2!='\0'&&*c1!='\0'){
		while(*c1==' '&&*c1!='\0'){
			c1++;
		}
		if(*c1=='\0') break;
		c2=c1;
		while(*c2!=' '&&*c2!='\0'){
			c2++;
		}
		if(c2-c1>max){
			max=c2-c1;
			c3=c1;
		}
		c1=c2+1;
	}
	while(*c3!=' '&&*c3!='\0'){
		printf("%c",*c3);
		c3++;
	}
}
int main(){
	char s[100];
	gets(s);
	fun(s);
	
}
