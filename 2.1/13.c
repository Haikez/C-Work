#include<stdio.h>
int main(){

	char str1[]="abcd";
	char str2[]="efg";
	printf("str1 = %s\nstr2 = %s\n",str1,str2);
	char str3[sizeof(str1)+sizeof(str2)];
	int i=0;
	for(i=0;i<sizeof(str1)-1;i++){
		str3[i]=str1[i];
	}
	for(int j=0;j<sizeof(str2)-1;j++){
		str3[i]=str2[j];
		i++;
	} 
	printf("%s\n",str3);
	return 0;	
}
