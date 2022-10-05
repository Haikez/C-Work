#include<iostream>
#include<vector>
using namespace std;
class Solution {
vector<int>B;
void MergeSort(vector<int>&nums,int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        MergeSort(nums,left,mid);
        MergeSort(nums,mid+1,right);
        int i=left,j=mid+1;
        for(int k=left;k<=right;k++){
            B[k]=nums[k];
        }
        int k=i;
        while(i<=mid&&j<=right){
            if(B[i]<=B[j]){
                nums[k++]=B[i++];
            }else{
                nums[k++]=B[j++];
            }
        }
        while(i<=mid) nums[k++]=B[i++];
        while(j<=right) nums[k++]=B[j++];
    }
}
public:
    vector<int> sortArray(vector<int>& nums) {
        B.resize(nums.size(),0);
        for(int i=0;i<nums.size();i++) B[i]=nums[i];
        MergeSort(nums,0,nums.size()-1);
        return nums;
    }
};