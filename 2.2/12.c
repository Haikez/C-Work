#include<stdio.h>
#include<math.h>
float fun(float a,float b,float c,float d,float x){
	float x1;
	while(1){
		float fx=a*x*x*x+b*x*x+c*x+d;
		float f=3*a*x*x+2*b*x+c;
		x1=-fx/f+x;
		if(fabs(x-x1)>=1e-5){
			x=x1;
		}else{
			break;
		}
	}
	return x1;
}
int main(){

	float ans=fun(1,2,3,4,1);
	printf("%f",ans);
	return 0;
}
