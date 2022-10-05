/* 给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。返回 需要移除区间的最小数量，使剩余区间互不重叠 。

示例 1:

输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/* 
    思路:
        将所有子区间按照左端点从小到大排序，定义一个right记录右端点，count用于记录删除的区间数。right初始为第一个区间的右端点。如果right小于等于下一个区间的左端点，说明没重叠，right更新到下一个区间的右端点。否则说明重叠，++count,right指向当前区间和下一个区间中较短的那一个右端点。因为只有当前区间的右端点越小，与下一个区间重叠的可能性也就越小。
 */
static bool cmp(vector<int> &A, vector<int> &B)
{
    return A[0] < B[0];
}
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n == 0)
    {
        return 0;
    }
    sort(intervals.begin(), intervals.end(), cmp);
    int right = intervals[0][1];
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (right<=intervals[i][0])
        {
            right=intervals[i][1];
        }else{
            count++;
            right=min(intervals[i][1],right);
        }
    }
    return count;
}
int main()
{
    vector<vector<int>> intervals = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};
    cout << eraseOverlapIntervals(intervals);
}