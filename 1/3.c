#include<stdio.h>
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	int ans=1;
	if(m<n){
		int tmp=m;
		m=n;n=tmp;
	}
	for(int i=1;i<=n;i++){
		if(m%i==0&&n%i==0){
			ans=i;
		}
	}
	printf("最大公约数为:%d,最小公倍数为:%d\n",ans,m*n/ans);
}
