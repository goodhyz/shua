#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount+1,amount+1); // 
    dp[0] = 0;
    int n = coins.size();
    for(int i=1;i<=amount;i++){
        for(int j=0;j<n;j++){
            if(i>=coins[j]){
                dp[i] = min(dp[i],dp[i-coins[j]]+1); // 
            }
        }
    }
    return dp[amount]>amount? -1: dp[amount];
  }
};

int main() {
    vector<int> coins = {1};
    int amount = 2;
    Solution sol;
    cout<<sol.coinChange(coins, amount)<<endl;
}