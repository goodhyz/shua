#include <vector>

using namespace std;

class Solution {
  public:
    int maxProfit(int k, vector<int> &prices) {
        vector<int> profits;
        if (prices.size() == 1)
            return 0;
        int p1 = 0, p2 = 1;
        while (p2 < prices.size()) {
            if (prices[p2] < prices[p1]) {
                int profit = prices[p2 - 1] - prices[p1];
                p1 = p2;
                p2++;
                if(profit>0)profits.push_back(profit);
            } else {
                p2++;
            }
        }
    }
};