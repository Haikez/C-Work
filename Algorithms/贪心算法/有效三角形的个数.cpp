/* 
给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。

示例 1:

输入: nums = [2,2,3,4]
输出: 3
解释:有效的组合是: 
2,3,4 (使用第一个 2)
2,3,4 (使用第二个 2)
2,2,3
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/* 
    三角形两边之和大于第三边a+b>c,a+c>b,b+c>a,若我们将数组排序好，则a<=b<=c,此时只要保证a+b>c则abc一定能构成三角形
    a=nums[i]
    b=nums[j]
    c=nums[k]
    用两重for循环依次枚举a和b保证a<b,则在下标nums[j+1,n-1]内用二分法找到第一个nums[i]+nums[j]<=nums[k]的数,那么当满足的三角形数为(k-j);
 */
int triangleNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    if (nums.size()<3)
    {
        return false;
    }
    int a=nums[0],b=nums[1],n=nums.size();
    int ans=0;
    for (int i = 0; i < n-2; i++)
    {
        a=nums[i];
        for (int j = i+1; j < n-1; j++)
        {
            b=nums[j];
            int left=j+1,right=n-1;
            int k=j;
            while (left<=right)
            {
                int mid=(left+right)/2;
                //找到小于a+b的最大下标
                if (nums[mid]<a+b)
                {
                    k=mid;
                    left=mid+1;
                }else
                {
                    right=mid-1;
                }
            }
            ans+=k-j;
        }
    }
    return ans;
}
int main(){
    vector<int> nums = {4,2,3,4};
    cout<<triangleNumber(nums);
}