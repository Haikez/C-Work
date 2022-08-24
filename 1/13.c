#include<stdio.h>
#include<stdbool.h>
int main(){
	float num = 0;
	scanf("%f",&num);
	float a=1.0,b=1.0;
	while(true){
		b=(num/a+a)/2.0;
	    if(a>=b&&a-b<1e-5||a<b&&b-a<1e-5){
	    	break;
	    }
		a=b;
	}
	printf("%f",b);
	return 0;
}
