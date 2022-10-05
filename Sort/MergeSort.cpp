#include <iostream>
using namespace std;
#define maxSize 100
void Merge1(int A[], int left, int mid, int right)
{
    //用直接插入排序合并;
    int j, k;
    for (int i = mid + 1; i <= right; i++)
    {
        j = i;
        k = A[i];
        while (j > 0 && A[j - 1] > k)
        {
            A[j] = A[j - 1];
            --j;
        }
        A[j] = k;
    }
}
int B[maxSize];
void Merge(int A[], int left, int mid, int right)
{
    int i, j, k;
    for (k = left; k <= right; k++)
    {
        B[k] = A[k];
    }
    for (i = left, j = mid + 1, k = i;j<=right&&i<=mid; k++)
    {
        if (B[i]<=B[j])
        {
            A[k]=B[i++];
        }else{
            A[k]=B[j++];
        }
    }
    while (i<=mid)
        A[k++]=B[i++];
    
    while (j<=right)
        A[k++]=B[j++];
    
}
void MergeSort(int A[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) >> 1;
        MergeSort(A, left, mid);
        MergeSort(A, mid + 1, right);
        Merge(A, left, mid, right);
    }
}
int main()
{
    int A[] = {0, 38, 17, 0, 12, 5, 7, 9, -19, -20, 100};
    MergeSort(A, 0, sizeof(A) / sizeof(int) - 1);
    for (int i = 0; i < sizeof(A) / sizeof(int); i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}