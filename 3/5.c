#include<stdio.h>
int main(){
	int n;
	int arr[100];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		arr[i]=i;
	}
	int j=1;
	int i=0;
	while(i<n-1){
		if(j>n) j%=n;
		while(arr[j]==-1) j++;	
		j++;
		if(j>n) j%=n;
		while(arr[j]==-1) j++;
		j++;
		if(j>n) j%=n;
		while(arr[j]==-1) j++;
		if(j>n) j%=n;
		arr[j++]=-1;
		i++;
	}
	for(int i=1;i<=n;i++){
		if(arr[i]!=-1){
			printf("%d ",arr[i]);
		}
	}
}
