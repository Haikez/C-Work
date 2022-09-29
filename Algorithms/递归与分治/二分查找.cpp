#include<iostream>
using namespace std;
//给定一个升序数组A,返回值为x的数的下标，没有则返回-1;
int BinarySearch(int A[],int n,int x){
    int left=0,right=n-1;
    int mid=-1;
    while (left<=right)
    {
        mid=(left+right)/2;
        if (A[mid]==x)
        {
            return mid;
        }else if(A[mid]<x){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return -1; 
}
//给定一个升序数组，返回大于等于x的最小值下标
int BinarySearch1(int A[],int n,int x){
    int left=0,right=n-1;
    int mid=-1,ans=-1;
    while (left<=right)
    {
        mid=(left+right)/2;
        if(A[mid]>=x){
            ans=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return ans;

}
//给定一个升序数组，返回小于等于x的最大值下标
int BinarySearch2(int A[],int n,int x){
    int left=0,right=n-1;
    int ans=-1,mid=-1;
    while (left<=right)
    {
        mid=(left+right)/2;
        if(A[mid]<=x){
            ans=mid;
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return ans;
    
}
int main(){
    int A[]={-9,-8,-4,-1,1,2,2,3,5,6,14,17,19,22};
    cout<<BinarySearch2(A,sizeof(A)/sizeof(int),20);
}