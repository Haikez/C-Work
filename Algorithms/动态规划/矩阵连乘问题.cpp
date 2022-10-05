#include <iostream>
#define maxSize 100
using namespace std;
/*
    思想：
        1. m[i][j]表示从矩阵i乘到矩阵j的最优解。
        2. 分别计算矩阵链长度从2一直到n的每个矩阵链连乘的最优解。将结果保存到m数组中。
        3. j指向以下标i开头矩阵链长度r结尾的下标，即j=i+r-1; 从i+1到k处依次断开，比较出i~j处的断开的最优解。将结果保存到m数组中
 */
void MatrixChain(int *p, int n, int m[][maxSize], int s[][maxSize])
{
    for (int i = 1; i <= n; i++)
    {
        //初始化
        m[i][i] = 0;
    }
    for (int r = 2; r <= n; r++)
    {
        for (int i = 1; i <= n - r + 1; i++)
        {
            int j = i + r - 1;
            //给m[i][j]初始值为，从i处断开的乘法大小
            m[i][j] = m[i][i] +m[i + 1][j] + p[i - 1] * p[i] * p[j];
            // s数组记录下标位置
            s[i][j] = i;
            for (int k = i + 1; k < j; k++)
            {
                //在i~j中依次断开比较
                int t =  m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}
int main()
{
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    int m[maxSize][maxSize];
    int s[maxSize][maxSize];
    MatrixChain(p, 7, m, s);
    for (int i = 1; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}