#include <iostream>
using namespace std;
#define maxSize 100
int sqrt1(int x)
{
    int low = 0;
    int high = x;
    int mid = (low + high) / 2;
    while ((high - low) > 1)
    {
        if (mid * mid > x)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
        mid = (low + high) / 2;
    }
    return mid;
}
int search(int A[], int n, int target)
{ // n为数组长度
    int i = 0;
    if (A[0] > target)
    {
        //如果数组中第一个元素比target大，则从后往前找。
        i = n - 1;
        while (A[i] > target)
            i--;
        if (A[i] == target)
        {
            return i;
        }
        else
            return -1;
    }
    else
    {
        //否则从前往后找。
        while (A[i] < target)
            i++;
        if (A[i] == target)
        {
            return i;
        }
        else
            return -1;
    }
}
// {6, 8, 10, 0, 2, 4};
int search2(int A[], int n, int target)
{
    int low = 0, high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (A[mid] == target)
            return mid;
        if (A[mid] > A[low])
        {
            if (A[mid] >= target && A[low] <= target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (A[mid] <= target && A[high] >= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
char *longestCommonPrefix(char **strs, int n)
{
    int min = strlen(strs[0]);
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < min && j < strlen(strs[i]); j++)
        {
            if (strs[0][j] == strs[i][j])
            {
                count++;
            }
            else
                break;
        }
        if (count < min)
            min = count;
    }
    char *result = new char(min);
    memcpy(result, strs[0], min);
    return result;
}
int reverse(int x)
{
    int flag = 0;
    int temp = x;
    int res = 0;
    if (x < 0)
    {
        flag = 1;
        temp = -x;
    }
    while (temp)
    {
        res *= 10;
        res += temp % 10;
        temp /= 10;
    }
    if (flag)
        return -res;
    else
        return res;
}
int transform(int x)
{
    int res = 0;
    int count = 1;
    while (x)
    {
        res += (x % 10) * count;
        count *= 2;
        x /= 10;
    }
    return res;
}
void reverse_char_fun(char str[], int low, int high)
{
    for (; low < high; low++, high--)
        swap(str[low], str[high]);
}
void reverse_str(char str[])
{
    // arr记录空格所在下标
    int arr[maxSize] = {0};
    arr[0] = -1;
    int j = 1;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            arr[j] = i;
            j++;
        }
        else if (str[i] >= 97)
        {
            str[i] -= 32;
        }
        else
        {
            str[i] += 32;
        }
    }
    arr[j] = strlen(str);
    for (int i = 0; i <= j; i++)
    {
        reverse_char_fun(str, arr[i] + 1, arr[i + 1] - 1);
    }
    reverse_char_fun(str, 0, strlen(str) - 1);
}
int search_min(int A[], int n)
{
    int low = 0, high = n - 1;
    int mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (A[low] < A[mid])
        {
            low = mid + 1;
        }
        else if (A[low] == A[mid])
        {
            high = high - 1;
        }
        else
        {
            high = mid;
        }
    }
    return A[mid];
}
int count_num(int A[], int n, int k)
{
    int low = 0, high = n - 1;
    while (A[low] != k && low < high)
        low++;
    while (A[high] != k && low < high)
        high--;

    if (low > high)
    {
        return -1;
    }
    return high - low + 1;
}
void move_0(int A[], int n)
{
    int i, j;
    for (i = 0, j = 0; j < n;)
    {
        if (A[j] != 0)
        {
            A[i] = A[j];
            ++i;
            ++j;
        }
        else
        {
            ++j;
        }
    }
    for (; i < n; i++)
        A[i] = 0;
}
int add(char str1[], char str2[])
{
    int a = 0, b = 0;
    int i = 0;
    while (str1[i] != '\0')
    {
        a *= 10;
        a += str1[i] - '0';
        ++i;
    }
    i = 0;
    while (str2[i] != '\0')
    {
        b *= 10;
        b += str2[i] - '0';
        ++i;
    }
    return a + b;
}
int main()
{
    // 2
    int A[] = {6, 8, 10, 0, 2, 4};
    cout << search2(A, 6, 4);
    // 3
    // char *str[100] = {"flowers", "flow", "flight"};
    // char *result = longestCommonPrefix(str, 3);
    // cout << result;
    // 4
    // cout<<reverse(124826);
    // 5
    // cout<<transform(111);
    // 6
    // char str[maxSize] = "This is a sample";
    // reverse_str(str);
    // cout<<str;
    // 7
    // int A[]={3,4,5,0,1,2};
    // cout<<search_min(A,5);
    // 8
    // int A[]={1,2,3,3,3,3,4,5};
    // cout<<count_num(A,8,3);
    // 9
    // int A[]={1,2,3,0,4};
    // move_0(A,5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout<<A[i]<<" ";
    // }
    // 10
    // cout << add("124123", "990");
    return 0;
}