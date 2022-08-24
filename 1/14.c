#include<stdio.h>
#include<math.h>
double fx(double x){
	return 2*x*x*x-4*x*x+3*x-6;
}
double f(double x){
	return 6*x*x-8*x+3;
}
int main(){
	double x0=1.5;
	double x1=x0-fx(x0)/f(x0);
	while(fabs(x0-x1)>=1e-5){
		x0=x1;
		x1=x0-fx(x0)/f(x0);
	}
	printf("%lf",x0);
}
