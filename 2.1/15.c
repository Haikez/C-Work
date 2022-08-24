#include<stdio.h>
int main(){

	char s1[100]="abcdefg";
	char s2[100]="hijklmnopq";
	printf("复制前\ns1:%s\ns2:%s\n",s1,s2);
	int i=0;
	while(s2[i]!='\0'){
		s1[i]=s2[i];
		i++;
	}		
	s1[++i]='\0';
	printf("复制后\ns1:%s\ns2:%s\n",s1,s2);
	return 0;
}
