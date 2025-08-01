#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int k = 2;
        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);
        for (int price : prices) {
            // i=0 表示卖1，买1
            for (int i = 1; i <= k; i++) {
                buy[i] = max(buy[i], sell[i - 1] - price);
                sell[i] = max(sell[i], price + buy[i]);
            }
        }
        return sell[k];
    }
};

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    Solution s;
    s.maxProfit(prices);
}