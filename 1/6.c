#include<stdio.h>
int main(){
	int n=0,ans=0,tmp=1;
	scanf("%d",&n);
	if(n<0) return 0;
	for(int i=1;i<=n;i++){
		tmp=tmp*i;
		ans+=tmp;
	}
	printf("结果是%d",ans);
}
