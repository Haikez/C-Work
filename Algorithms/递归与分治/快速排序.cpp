#include <iostream>
using namespace std;
void QuickSort(int A[], int left, int right)
{
    int p = left, q = right;
    if (left < right)   //if是递归的出口
    {
        int key = A[p];
        while (p < q)
        {
            while (p < q && A[q] >= key)//时刻记住p<q
                --q;
            if (p < q)  //赋值前先判断p<q
            {
                A[p] = A[q];
            }
            while (p < q && A[p] <= key)
                ++p;
            if (p < q)
            {
                A[q] = A[p];
            }
        }
        A[p] = key;
    }
    else
        return;
    QuickSort(A, left, p - 1);
    QuickSort(A, p + 1, right);
}
int main()
{
    int A[] = {0, 38, 17, 0, 12, 5, 7, 9, -19, -20, 100};
    QuickSort(A, 0, sizeof(A) / sizeof(int)-1);
    for (int i = 0; i < sizeof(A) / sizeof(int); i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}