#include<iostream>
using namespace std;
int getIndex(int A[],int left,int right){
    //每次定位数组中第一个元素在数组中的位置，并返回下标
    int key=A[left];
    while(left<right){
        while (left<right&&A[right]>=key)
            --right;
        if (left<right)
        {
            A[left++]=A[right];
        }
        while (left<right&&A[left]<=key)
            left++;
        if (left<right)
        {
            A[right--]=A[left];
        }
        
    }
    A[left]=key;
    return left;
}
//查找数组总第k小的元素的值，要求时间复杂度O(n)
int select(int A[],int left,int right,int k){
    if (left==right)
    {
        return A[left];
    }
    int i=getIndex(A,left,right);
    int j=i-left+1;
    if (k<=j)
    {
        return select(A,left,i,k);
    }else   
        return select(A,i+1,right,k-j);
    
}
int main(){
    int A[] = {0, 38, 17, 0, 12, 5, 7, 9, -19, -20, 100};
    cout<<select(A,0,sizeof(A)/sizeof(int)-1,6);
    return 0;
}