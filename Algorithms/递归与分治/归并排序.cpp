#include<iostream>
using namespace std;
void Merge(int A[],int left,int mid,int right){
    //用直接插入排序合并;
    int j,k;
    for (int i = mid+1; i <=right; i++)
    {
        j=i;k=A[i];
        while (j>0&&A[j-1]>k)
        {
            A[j]=A[j-1];
            --j;
        }
        A[j]=k;
    }
}
void MergeSort(int A[],int left,int right){
    if (left<right)
    {
        int mid=(left+right)>>1;
        MergeSort(A,left,mid);
        MergeSort(A,mid+1,right);
        Merge(A,left,mid,right);
    }
}
int main(){
    int A[] = {0, 38, 17, 0, 12, 5, 7, 9, -19, -20, 100};
    MergeSort(A,0,sizeof(A) / sizeof(int)-1);
    for (int i = 0; i < sizeof(A) / sizeof(int); i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}