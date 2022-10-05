/* 
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
返回 你能获得的 最大 利润 。

示例 ：
输入：prices = [7,1,5,3,6,4]
输出：7
解释：
在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。总利润为 4 + 3 = 7 。
*/
#include<iostream>
#include<vector>
using namespace std;

/* 
    思路：只要有利可图，那我就进行买卖
    遍历数组，记录历史最低点,只要我今天的价格比历史最低点高，那我就假设我在历史最低点买的，在今天卖了。然后更新一下收益。由于已经进行了交易，那么将历史最低点更新到今天。
 */
int maxProfit(vector<int>& prices) {
    int min_num=prices[0];
    int sum=0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i]>min_num)
        {
            sum+=(prices[i]-min_num);
        }
        min_num=prices[i];
    }
    return sum;
}
/* 
    思路2：只要今天的价比昨天的高，就进行交易
 */
int maxProfit2(vector<int>& prices) {
    int sum=0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i]>prices[i-1])
            sum+=prices[i]-prices[i-1];
        
    }
    return sum;
}
int main(){
    vector<int> prices={7,1,5,3,6,4};
    cout<<maxProfit2(prices);
}