#include<iostream>
using namespace std;
void InsertSort(int A[],int n){
    int j,k;
    for (int i = 1; i < n; i++)
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
int main(){
    int A[] = {0, 38, 17, 0, 12, 5, 7, 9, -19, -20, 100};
    InsertSort(A,sizeof(A) / sizeof(int));
    for (int i = 0; i < sizeof(A) / sizeof(int); i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}