#include<stdio.h>
int main(){

	for(int i=2;i<=100;i++){
		for(int j=2;j<=i;j++){
			if(i%j==0&&j!=i){
				break;
			}
			if(j==i) printf("%d ",j);
		}
	}
	return 0;
}
