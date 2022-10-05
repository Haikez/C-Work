#include<iostream>
#include<vector>
using namespace std;
void InsertFun(int A[],int m,int B[],int n){
    while (A[m-1]>B[0])
    {
        int j=m-1;
        int temp=A[j];
        while (j>0&& A[j-1]>B[0])
        {
            A[j]=A[j-1];
            j--;
        }
        A[j]=B[0];
        B[0]=temp;
        for (int i = 0; i < n-1; i++)
        {
            if (B[i]>B[i+1])
            {
                swap(B[i],B[i+1]);
            }
        }
    }
}
int main(){
    int A[]={4,12,28};
    int B[]={1,7,9,29,45};
    InsertFun(A,3,B,5);
    for (int i = 0; i < 3; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<B[i]<<" ";
    }
    
}