#include<stdio.h>
void fun(char *s){
	for(int i=0;i<10-1;i++){
		for(int j=0;j<10-i-1;j++){
			if(s[j]>s[j+1]){
				char tmp=s[j];
				s[j]=s[j+1];
				s[j+1]=tmp;
			}
		}
	}

}
int main(){

	char s[11]="ajidkbnmdq";
	fun(s);

	printf("%s",s);
	return 0;

}
