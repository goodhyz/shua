#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    // 空间O(n)  时间O(n)
    // dp[i] 以i结尾的最大长度
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        int max_sum = dp[0];
        for(int i=1;i<n;i++){
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            max_sum = max(max_sum,dp[i]);
        }
        return max_sum;
    }

    // dp只依赖于前一个num
    int maxSubArray1(vector<int> &nums) {
        int pre = 0, ans = nums[0];
        for (auto num : nums) {
            pre = max(pre + num, num);
            ans = max(ans, pre);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    cout << s.maxSubArray(nums) << endl;
}