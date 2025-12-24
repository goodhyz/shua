#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n);
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};

int main(){
    vector<int> nums={8,1,1,8};
    Solution s;
    cout<<s.rob(nums)<<endl;
}