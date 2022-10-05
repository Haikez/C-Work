#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int>B; 
    int MergeSort(vector<int>&nums,int left,int right){
        if (left>=right)
        {
            return 0;
        }
        int mid=(left+right)/2;
        int len=right-left+1;
        int lnum=MergeSort(nums,left,mid);
        int rnum=MergeSort(nums,mid+1,right);
        int res=lnum+rnum;
        for (int k = left; k <= right; k++)
        {
            B[k] = nums[k];
        }
        int i=left,j=mid+1,k=i;
        while(i<=mid&&j<=right)
        {
            if (B[i]<=B[j])
            {
                nums[k++]=B[i++];
            }else{
                nums[k++]=B[j++];
                res+=mid-i+1;
            }
        }
        while (i<=mid){
            nums[k++]=B[i++];
        }
        while (j<=right){
            nums[k++]=B[j++];
        }
        return res;
    }
    int reversePairs(vector<int>& nums) {
        B.resize(nums.size(),0);
        for(int i=0;i<nums.size();i++){
            B[i]=nums[i];
        }
        return MergeSort(nums,0,nums.size()-1);
    }
};