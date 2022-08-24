#include<stdio.h>
int main(){
	char s[100];
	gets(s);
	int i=0;
	int a=0,b=0,c=0,d=0,e=0;
	while(s[i]!='\0'){
		if(s[i]>='A'&&s[i]<='Z'){
			a++;
		}else if(s[i]>='a'&&s[i]<='z'){
			b++;
		}else if(s[i]==' '){
			c++;
		}else if(s[i]>='0'&&s[i]<='9'){
			d++;
		}else{
			e++;
		}
		i++;
	}
	printf("大写字母个数:%d\n",a);
	printf("小写字母个数:%d\n",b);
	printf("空格个数:%d\n",c);
	printf("数字个数:%d\n",d);
	printf("其余字符个数:%d\n",e);
}
