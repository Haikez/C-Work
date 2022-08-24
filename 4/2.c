#include<stdio.h>
void reverse(int arr[],int a,int b){
	for(int i=a,j=b;i<j;i++,j--){
		int tmp=arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
	}
}
int main(){
	//1.
	reverse(A,0,n-1);
	//2.
	reverse(A,0,k-1);
	reverse(A,0,n-1);
	//3.
	reverse(A,0,k-1);
	reverse(A,k,n-1);
	reverse(A,0,n-1);
}
