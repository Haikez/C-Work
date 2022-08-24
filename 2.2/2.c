#include<stdio.h>
#include<math.h>
void f(float a,float b,float c){

	float dt = b*b-4*a*c;
	if(dt<0) printf("该方程无解\n");
	else if(dt==0){
		float x1=(-b+sqrt(dt))/2*a;
		printf("x1=x2=%f",x1);
	}else{
		float x1=(-b+sqrt(dt))/2*a;
		float x2=(-b-sqrt(dt))/2*a;
		printf("x1=%f\tx2=%f",x1,x2);
	}
	return;
}

int main(){
	float a,b,c;
	scanf("%f %f %f",&a,&b,&c);
	f(a,b,c);
	return 0;
}
