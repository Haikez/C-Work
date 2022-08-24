#include<stdio.h>
void fun(char *s){
	int len=0;
	while(s[len]!='\0'){
		len++;
	}
	for(int i=0;i<len/2;i++){
		char tmp=s[i];
		s[i]=s[len-i-1];
		s[len-i-1]=tmp;
	}
	return;

}
int main(){
	char s[100];
	gets(s);
	printf("逆转前:%s\n",s);
	fun(s);
	printf("逆转后:%s\n",s);
}
