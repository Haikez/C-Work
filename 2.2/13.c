#include<stdio.h>
float P(float n,float x){
	if(n==0) return 1;
	if(n==1) return x;
	return ((2*n-1)*x-P(n-1,x)-(n-1)*P(n-2,x))/n;
}
int main(){
	printf("n=5,x=5:\n");
	printf("%f",P(5,5));

}
