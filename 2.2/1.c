#include<stdio.h>
int* func(int a,int b){
	int ans[2]={1,1};
	int *p = ans;
	if(a>b){
		int tmp=a;
		a=b;b=tmp;
	}
	int i=2;
	while(i<=a){
		if(a%i==0&&b%i==0){
			ans[0]=i;
		}
		i++;
	}
	ans[1]=a*b/ans[0];
	return p;	
}
int main(){
	int a,b;
	int *ans;
	printf("请输入两个数:");
	scanf("%d %d",&a,&b);
	ans = func(a,b);
	printf("最大公约数:%d\n最小公倍数:%d\n",ans[0],ans[1]);
	return 0;
}

