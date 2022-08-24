#include<stdio.h>
int main(){
	char str[241]="vHaskfjiasjd12355al;djf alkdjhfajlk asdkfhhILKJKHalkdfjOIHdkfjjkjdjddfdfdfdwd a\nvHaskfjiasjdflkjal;djf alkdjhfajlk asdkfhhILKJKHalkdfjOIHdkfjjkjdjddfdfdfdwd a\nvHaskfjiasjdflkjal;djf alkdjhfajlk asdkfhhILKJKHalkdfjOIHdkfjjkjdjddfdfdfdwd a\n";
	int a=0,b=0,c=0,d=0,e=0;
	for(int i=0;i<sizeof(str)-1;i++){
		if(str[i]>='a'&&str[i]<='z'){
			a++;
		}else if(str[i]>='A'&&str[i]<='Z'){
			b++;
		}else if(str[i]>='0'&&str[i]<='9'){
			c++;
		}else if(str[i]==' '){
			d++;
		}else{
			e++;
		}
	}
	printf("大写字母:%d\n小写字母%d\n数字%d\n空格:%d\n其他:%d",b,a,c,d,e);
	return 0;
}
