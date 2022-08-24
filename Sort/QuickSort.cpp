#include <iostream>
using namespace std;
void QuickSort1(int A[], int low, int high)
{ //赋值替换法
    int p = low, q = high;
    if (p < q)
    {
        int key = A[p];
        while (p < q)
        {
            while (p < q && A[q] > key)
                --q;
            if (p < q)
            {
                A[p] = A[q];
                p++;
            }
            while (p < q && A[p] < key)
                ++p;
            if (p < q)
            {
                A[q] = A[p];
                q--;
            }
        }
        A[p] = key;
    }
    else
        return;
    QuickSort1(A, low, p - 1);
    QuickSort1(A, p + 1, high);
}
void QuickSort2(int A[], int low, int high)
{
    int p = low, q = high;
    if (p < q)
    {
        int key = A[p];
        while (p < q)
        {
            while (p < q && A[q] >= key)
                --q;
            while (p < q && A[p] <= key)
                ++p;
        }
    }
}
int main()
{
    int A[] = {1, 4, 2, 6, 6, 8, 2, 9, 0};
    QuickSort1(A, 0, 8);
    for (int i = 0; i < 9; i++)
    {
        cout << A[i] << " ";
    }
}