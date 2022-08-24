#include<stdio.h>
void fun(char *s1,char *s2){
	int j=0;
	for(int i=0;s1[i]!='\0';i++){
		if(s1[i]=='a'||s1[i]=='e'||s1[i]=='i'||s1[i]=='o'||s1[i]=='u'){
			s2[j]=s1[i];
			j++;
		}
	}
	s2[j]='\0';
}
int main(){
	char s1[100];
	char s2[100];
	gets(s1);
	gets(s2);
	fun(s1,s2);
	printf("%s",s2);
}
