/*
121
the best time to purchase a stock 1
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // 贪心
    int maxProfit(vector<int> &prices) {
        int min_price = prices[0];
        int max_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < min_price) {
                min_price = prices[i];
            } else {
                max_profit = max(max_profit, prices[i] - min_price);
            }
        }
        max_profit = max(max_profit, 0);
        return max_profit;
    }
};