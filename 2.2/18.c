#include<stdio.h>
int main(){
	int year,mon,day;
	int cnt=0;
	scanf("%d %d %d",&year,&mon,&day);
	int arr[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(year%4==0) arr[1]=29;
	for(int i=0;i<mon-1;i++){
		cnt+=arr[i];
	}
	cnt+=day;
	printf("是第%d天\n",cnt);
}
