#include<iostream>
#include"math.h"
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=sqrt(n);
    while (a*(a+1)<n*2)
        a++;
    int start=1;
    for (int i = 1; i < a; i++)
    {
        start+=2*i-1;
    }
    int res=start+(n-a*(a-1)/2-1)*2;
    cout<<res;
}