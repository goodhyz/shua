/*
Jump Game II
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
return the minimum number of jumps required to reach the last index.
https://leetcode.cn/problems/jump-game-ii/?envType=study-plan-v2&envId=top-interview-150
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // 动态规划 时间复杂度O(n^2) 空间复杂度O(n)
    int jump(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(n, n + 1);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= nums[i] && i + j < n; j++) {
                dp[i + j] = min(dp[i] + 1, dp[i + j]);
            }
        }
        return dp[n - 1];
    }

    // 滑动窗口 left right 更新一次加一个step
    int jump1(vector<int> &nums){
        int n =nums.size();
        int step =0;
        int left=0,right =0;
        while(right<n-1){
            int maxPos = 0;
            for(int i = left;i<=right;i++){
                maxPos = max(maxPos,i+nums[i]);
            } 
            left = right+1;
            right = maxPos;
            step++;
        }
        return step;
    }

    // 贪心 从左往右
    int jump2(vector<int> &nums){
        int n = nums.size();
        int maxPos = 0;
        int end = 0;
        int step = 0;
        for(int i = 0;i<n-1;i++){
            maxPos = max(maxPos,i+nums[i]);
            if(i==end){
                end = maxPos;
                step++;
            }
        }
        return step;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2,3,1,1,4};
    int result = solution.jump1(nums);
    cout<<result<<endl;
    return 0;
}