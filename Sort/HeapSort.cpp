#include <iostream>
using namespace std;

void adjust(int R[], int low, int high)
{
    int i = low, j = 2 * i;
    int temp = R[low];
    while (j <= high)
    {
        if (j < high && R[j] < R[j + 1])
        {
            ++j; // j指向较大的那个子节点。
        }
        if (R[j] > temp)
        {
            R[i] = R[j];
            i = j;
            j = 2 * i;
        }
        else
            break;
    }
    R[i] = temp;
}
void heapSort(int R[], int n)
{
    int temp, i;
    //从最后一个结点向前建立大根堆
    for (i = n / 2; i >= 1; --i) // i指向最后一个非叶子结点。这个for循环结束后形成一个大顶堆。
        adjust(R, i, n);
    
    for (i = n; i >= 2; --i)
    { //将大顶堆的根节点和最后一个节点交换。
        swap(R[i],R[i]);
        adjust(R, 1, i - 1); //对1~i-1个元素进行调整。
    }
}
int main()
{
    int Norank[9] = {0, 48, 38, 65, 97, 76, 13, 27, 49};
    heapSort(Norank, 8);

    for (int i = 1; i <= 8; ++i)
        cout << Norank[i] << " ";
    return 0;
}