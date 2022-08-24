#include<stdio.h>
int main(){

	char str[]="ABCDEFG 12345 abcdefg";
	printf("原文是:%s\n",str);
	for(int i=0;i<sizeof(str)-2;i++){
		if(str[i]>='a'&&str[i]<='z'){
			str[i]='a'+'z'-str[i];
		}else if(str[i]>='A'&&str[i]<='Z'){
			str[i]='A'+'Z'-str[i];
		}
	}	
	printf("密码是%s",str);
	return 0;
}
