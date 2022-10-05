#include<iostream>
#include<vector>
using namespace std;
int MergeSort(vector<int>&nums,int left,int right){
    if (left>=right)
    {
        return 0;
    }
    int mid=(left+right)>>1;
    int len=right-left+1;
    int lnum=MergeSort(nums,left,mid);
    int rnum=MergeSort(nums,mid+1,right);
    int res=lnum+rnum;

    int i,j,k;
    int *B=(int *)malloc(sizeof(int)*len);
    for (k = left; k <= right; k++)
    {
        B[k] = nums[k];
    }
    for (i = left, j = mid + 1, k = i;j<=right&&i<=mid; k++)
    {
        if (B[i]<=B[j])
        {
            nums[k]=B[i++];
        }else{
            res+=mid-i+1;
            nums[k]=B[j++];
        }
    }
    while (i<=mid)
        nums[k++]=B[i++];
    while (j<=right)
        nums[k++]=B[j++];
    return res;
}
int reversePairs(vector<int>& nums) {
    return MergeSort(nums,0,nums.size()-1);
}
int main(){
    vector<int>nums={7,5,6,4,2};
    cout<<reversePairs(nums);
}