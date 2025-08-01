/*
122
the best time to purchase a stock 2
https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/solutions/476791/mai-mai-gu-piao-de-zui-jia-shi-ji-ii-by-leetcode-s/?envType=study-plan-v2&envId=top-interview-150
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
      // 贪心算法，只要后一天比前一天高，就卖出
      int maxProfit1(vector<int>& prices) {
          int total=0;
          for(int i=1;i<prices.size();i++){
              if(prices[i]>prices[i-1])total+=prices[i]-prices[i-1];
          }
          return total;
      }

      // 动态规划
      int maxProfit (vector<int>& prices) {
        // dp[i][0]表示第i天交易完后手里没有股票的最大利润
        // dp[i][1]表示第i天交易完后手里持有一支股票的最大利润
        int n = prices.size(); 
        int profit[n][2];
        profit[0][0] = 0;
        profit[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            profit[i][0] = max(profit[i - 1][0], profit[i - 1][1] + prices[i]);
            profit[i][1] = max(profit[i - 1][1], profit[i - 1][0] - prices[i]);
        }
        return profit[n - 1][0];
      }
  };

int main() {
    Solution solution;
    vector<int> prices = {7,1,5,3,6,4};
    int result = solution.maxProfit(prices);
    cout<<result<<endl;
    return 0;
}