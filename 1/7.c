/*************************************************************************
    > File Name: 7.c
# File Name: 7.c
# Author : Haikez  
# QQ : 1937086590
# Email:1937086590@qq.com
# Created Time: Wed 01 Jun 2022 01:23:43 BST
 ************************************************************************/
#include<stdio.h>
int main(){
	int k=0;
	float ans=0.0;
	scanf("%d",&k);
	for(int i=1;i<=100;i++){
		ans+=i;
	}
	for(int i=1;i<=50;i++){
		ans+=i*i;
	}
	for(float i=1;i<=10;i++){
		ans+=1/i;
	}
	printf("%f",ans);
	return 0;
}
