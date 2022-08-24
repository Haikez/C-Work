#include<stdio.h>
int main(){
	for(int i=1;i<=1000;i++){
		int count=0;
		for(int j=1;j<i;j++){
			if(i%j==0){
				count+=j;
			}
		}
		if(i==1) printf("1 its factors are 1\n");
		if(count==i){
			printf("%d its factors are 1",i);
			for(int j=2;j<i;j++){
				if(i%j==0){
					printf(",%d",j);
				}
			}
			printf("\n");
		}
	}


}
