/*************************************************************************
    > File Name: 4.c
# File Name: 4.c
# Author : Haikez  
# QQ : 1937086590
# Email:1937086590@qq.com
# Created Time: Thu 02 Jun 2022 00:19:21 BST
 ************************************************************************/
#include<stdio.h>
int main(){
	char str[100];
	gets(str);
	int i=0,a=0,b=0,c=0,d=0;
	while(str[i]!='\0'){
		if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z'){
			a++;
		}else if(str[i]>='0'&&str[i]<='9'){
			b++;
		}else if(str[i]==' '){
			c++;
		}else{
			d++;
		}
		i++;
	}
	printf("英文字母:%d\n空格:%d\n数字:%d\n其他:%d\n",a,c,b,d);
	return 0;
}
