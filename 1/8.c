#include<stdio.h>
int main(){
	for(int i=100;i<1000;i++){
		int a=i%10;
		int b=i%100/10;
		int c=i/100;
		if(a*a*a+b*b*b+c*c*c==i) printf("%d\n",i);
	}
}
