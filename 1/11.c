#include<stdio.h>
int main(){
	float h = 100;
	float cnt = 0;
	for(int i=0;i<9;i++){
		cnt += h;
		h/=2;
		cnt += h;
	}
	cnt +=h;
	printf("一共经过%f米，第十次反弹%f米",cnt,h/2);
	return 0;
}
