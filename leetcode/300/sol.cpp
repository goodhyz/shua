#include <algorithm>
#include <vector>


using namespace std;

class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int maxLen=1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]>nums[j]){
                    dp[i] = max(dp[j]+1,dp[i]);
                    maxLen = max(maxLen,dp[i]);
                }
            }
        }
        return maxLen;
    }
};

int main() {
    vector<int>nums = {1,3,6,7,9,4,10,5,6};
    Solution s;
    s.lengthOfLIS(nums);
}