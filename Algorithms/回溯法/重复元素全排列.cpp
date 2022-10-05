#include<iostream>
#include<vector>
using namespace std;
bool ok(vector<int> nums,int start,int i){
    if(i>start){
        for(int t=start;t<i;t++){
            if(nums[t]==nums[i]) 
                return false;
        }
    }
    return true;
}
vector<vector<int>> res;
vector<vector<int>> perm(vector<int>& nums,int start){
    if(start==nums.size()) res.push_back(nums);
    for(int i=start;i<nums.size();i++){
        if(ok(nums,start,i)){
            swap(nums[start],nums[i]);
            perm(nums,start+1);
            swap(nums[start],nums[i]);
        }
    }
    return res;
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    return perm(nums,0);
}
