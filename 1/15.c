#include<stdio.h>
#include<math.h>
double fx(double x){
	return 2*x*x*x-4*x*x+3*x-6;
}
int main(){
	double x0=-10;
	double x1=10;
	double xx=x0+(x1-x0)/2;
	while(fabs(x1-x0)>=1e-6&&x1>x0){
		if(fx(xx)==0) {
			printf("%lf",xx);
			return 0;
		}
		if(fx(xx)*fx(x1)>0){
			x1=xx;
		}else{
			x0=xx;
		}
		xx=x0+(x1-x0)/2;
	}
	printf("%lf",xx);
	return 0;
}
