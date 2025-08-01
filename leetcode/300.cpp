#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int max_len=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            max_len = max(dp[i],max_len);
        }
        return max_len;
    }
};

int main() {
    vector<int>nums = {1,3,6,7,9,4,10,5,6};
    Solution s;
    s.lengthOfLIS(nums);
}