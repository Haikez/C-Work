#include<iostream>
#include<vector>
using namespace std;
bool isTrue(int num,int k){
    for (int i = 2; i < num; i++)
    {
        if (num%i==0)
        {
            return false;
        }
    }
    int temp;
    while(num){
        temp=num%10;
        if (temp==k)
        {
            return false;
        }
        num/=10;
    }
    return true;
}
int main(){
    int n,k;
    cin>>n>>k;
    int res=0;
    for (int i = 2; i <= n; i++)
    {
        if (isTrue(i,k))
        {
            res++;
        }
    }
    cout<<res;
}