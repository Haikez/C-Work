#include<iostream>
#include<vector>
using namespace std;
//1. 将数组分成左边奇数，右边偶数
void P1(int A[],int n){
    int left=0,right=n-1;
    while(left<right){
        while (left<right&&A[right]%2==0)
        {
            --right;
        }
        if (left<right)
        {
            swap(A[left],A[right]);
        }
        while (left<right&&A[left]%2==1)
        {
            ++left;
        }
        if (left<right)
        {
            swap(A[left],A[right]);
        }
    }
}
//3. 严格二叉树

//4. 找出字符串中第一个只出现一次的字符
void FirstOne(char *str){
    int A[26]={0};
    int n=strlen(str);
    for (int i = 0; i < n; i++)
    {
        A[str[i]-'a']++;
    }
    for (int i = 0; i < n; i++)
    {
        if (A[str[i]-'a']==1)
        {
            cout<<str[i];
            return;
        }
    }
}
int main(){
    // 1.
    int A[]={2,4,5,6,8,9,1,3,4,2,5};
    P1(A,11);
    for (int i = 0; i < 11; i++)
    {
        cout<<A[i]<<" ";
    }
    
    // 4.
    // char str[]="aadccdgk";
    // FirstOne(str);

}