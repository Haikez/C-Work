/* 给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。

 

示例 1：

输入：nums = [1,2,3,4,5]
输出：true
解释：任何 i < j < k 的三元组都满足题意
 */
#include<iostream>
#include<vector>
using namespace std;
/* 
    思路:
        从左到右遍历数组nums,遍历过程中维护两个变量，first和second，分别表示递增的三元子序列中的第一个和第二个，任何时候都有first<second。

        初始时first=nums[0],second=+无穷，对于1<=i<n，当遍历到下标时，进行如下操作:
            1. 如果nums[i]>second，则找到了一个递增的三元子序列，返回true;
            2. 否则,如果nums[i]>first,则将second的值更新为nums[i]
            3. 否则，将first的值更新为nums[i]。
        如果遍历结束时没找到递增的三元子序列，返回false。

        上述做法的贪心思想是:为了找到递增的三元子序列，first和second应该尽可能的小，此时找到递增的三元子序列的可能性更大。
        
 */
bool increasingTriplet(vector<int>& nums) {
    if (nums.size()<3)
    {
        return false;
    }
    int first=nums[0],second=INT_MAX;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i]>second)
        {
            return true;
        }else if (nums[i]>first)
        {
            second=nums[i];
        }else{
            //此处很妙
            first=nums[i];
        }
    }
    return false;
}
int main(){
    vector<int>nums = {1,2,3,4,5};
    cout<<increasingTriplet(nums);

}