#include<stdio.h>
#include<math.h>
int fun(char *s){
	char *p=s;
	char *r=p-1;
	int ans=0,i=0;
	if(*p=='\0') return 0;
	while(*(p+1)!='\0') p++;
	while(p!=r){
		switch(*p){
		case 'A':ans=ans+pow(16,i)*10;
				break;
		case 'B':ans=ans+pow(16,i)*11;
				break;
		case 'C':ans=ans+pow(16,i)*12;
				 break;
		case 'D':ans=ans+pow(16,i)*13;
				 break;
		case 'E':ans=ans+pow(16,i)*14;
				 break;
		case 'F':ans=ans+pow(16,i)*15;
				 break;
		default:ans=ans+pow(16,i)*(*p-'0');
		}
		++i;
		p--;

	}
	return ans;
}
int main(){
	char s[]="1A818";
	printf("%d",fun(s));
	return 0;
}
