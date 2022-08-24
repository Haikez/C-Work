#include<stdio.h>
int main(){
	float ans =0,a=1,b=2;
    for(int i=1;i<=20;i++){
		ans=ans+b/a;
		float tmp=a;
		a=b;
		b=a+tmp;
		
    }
	printf("%f",ans);
	return 0;
}
