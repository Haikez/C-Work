#include <iostream>
using namespace std;
bool isHuiwen(char str[], int low, int high)
{
    if (low >= high)
    {
        return true;
    }
    if (str[low] == str[high])
    {
        return isHuiwen(str, low + 1, high - 1);
    }
    else
        return false;
}

float pow1(float x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    float res = x;
    int i = 1;
    while (i <= n / 2)
    {
        i *= 2;
        res *= res;
    }
    for (; i < n; i++)
    {
        res *= x;
    }
    return res;
}
int main()
{
    char str[] = "abba";
    // cout<< isHuiwen(str,0,3)<<endl;
    cout << pow1(3.000, 3);
}