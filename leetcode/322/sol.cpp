#include <iostream>
#include <vector>

using namespace std;

// 好像是一个背包问题，但是数量不限，不能直接用贪心做
class Solution1 {
  public:
    void quickSort(vector<int> &coins, int start, int end) {
        if (start > end)
            return;
        int pivot = coins[end];
        int l = start, r = end;
        while (l < r) {
            while (coins[l] >= pivot && r > l) {
                l++;
            }
            while (coins[r] <= pivot && r > l) {
                r--;
            }
            if (r != l)
                swap(coins[l], coins[r]);
        }
        swap(coins[l], coins[end]);
        quickSort(coins, start, l - 1);
        quickSort(coins, l + 1, end);
    }
    int coinChange(vector<int> &coins, int amount) {
        int count = 0, total = 0;
        quickSort(coins, 0, coins.size() - 1);
        for (int i = 0; i < coins.size(); i++) {
            int j = 0;
            while (total + j * coins[i] < amount) {
                j++;
            }
            if (total + j * coins[i] == amount)
                return count + j;
            count += j - 1;
            total += (j - 1) * coins[i];
        }
        return -1;
    }
};

class Solution {
    public:
      int coinChange(vector<int> &coins, int amount) {
          vector<int> dp (amount+1,amount+1);
          dp[0]=0;
          for(int i=1;i<dp.size();i++){
              for(const auto &coin:coins){
                  int x = i-coin;
                  if(x<0)continue;
                  dp[i]=min(dp[x]+1,dp[i]);
              }
          }
          return dp[amount]==amount+1?-1:dp[amount];
      }
  };