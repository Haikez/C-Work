#include<stdio.h>
int main(){

	char s1[100];
	char s2[100];
	printf("请输入s1:");
	gets(s1);
	printf("请输入s2:");
	gets(s2);

	int i=0;
	for(i=0;i<99;i++){
		if(s1[i]!=s2[i]){
			printf("%d",s1[i]-s2[i]);
			return 0;
		}
		if(s1[i]=='\0'||s2[i]=='\0') break;
	}	
	if(s1[i]!='\0'||s2[i]!='\0'){
		printf("%d",s1[i]-s2[i]);
	}else{
		printf("0");
	}
	return 0;
}
