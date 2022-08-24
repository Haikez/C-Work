#include<stdio.h>
void fun(int a[],int m,int n){
	for(int i=m;i<m+n;i++){
		int j;
		for(j=i-1;j>0;j--){
			if(a[j+1]<a[j]){
				a[j+1]=a[j];
			}else{
				break;
			}
		}
		a[j]=a[i];
	}

}
int main(){
	int a[]={1,3,5,7,9,2,4,6,8};
	fun(a,5,4);
	for(int i=0;i<9;i++){
		printf("%d ",a[i]);
	}
}
