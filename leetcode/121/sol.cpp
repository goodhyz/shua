/*
121
the best time to purchase a stock 1
*/
#include <iostream>
#include <string>
#include <sstream>

#include <vector>
using namespace std;
class Solution {
  public:
    // 贪心
    int maxProfit(vector<int> &prices) {
        int min_price = prices[0];
        int max_profit = 0;
        int n = prices.size();
        for(int i =1; i<n;i++){
            int profit = prices[i] - min_price;
            max_profit = max(max_profit,profit);
            min_price = min(min_price,prices[i]);
        }
        return max_profit;
    }
};

int main(){
    string line;
    getline(cin,line);
    stringstream ss(line);
    vector<int> nums;
    int num;
    while(ss>>num){
        nums.push_back(num);
    }
    Solution sol;
    cout<<sol.maxProfit(nums)<<endl;
}