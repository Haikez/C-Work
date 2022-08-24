#include<stdio.h>
void fun(int n){
	int i=1000;
	while(i!=0){
		if(i==1) printf("%c",n+'0');
		else{
			printf("%c ",n/i+'0');
		}
		n%=i;
		i/=10;
	}
}
int main(){
	int n=0;
	scanf("%d",&n);
	fun(n);

}
