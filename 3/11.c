#include<stdio.h>
#include<string.h>
void s_sort(char (*p)[10]){
	for(int i=0;i<10;i++){
		for(int j=0;j<9-i;j++){
			if(strcmp(*(p+j),*(p+j+1))>0){
				char t[10];
				strcpy(t,*(p+j));
				strcpy(*(p+j),*(p+j+1));
				strcpy(*(p+j+1),t);
			}
		}
	}
}
int main(){
	char str[10][10]={
		"abcdefg",
		"aabcdefg",
		"djfakldb",
		"asdf",
		"adfadafd",
		"aaaaa",
		"vasdfad",
		"dfadsfa",
		"dafjadkf",
		"dafqwer"
	};
	char (*s)[10];
	s=str;
	s_sort(s);
	for(int i=0;i<10;i++){
		printf("%s\n", str[i]);
	}

}
