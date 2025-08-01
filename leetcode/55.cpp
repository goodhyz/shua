/*
canJump
Given an array of non-negative integers, you are initially positioned at the first index of the array.
https://leetcode.cn/problems/jump-game/?envType=study-plan-v2&envId=top-interview-150
*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        // 动态规划 时间复杂度O(n^2) 空间复杂度O(n)
        bool canJump1(vector<int>& nums) {
            int n = nums.size();
            vector<bool> dp(n);
            dp[0] = true;
            for(int i=1;i<n;i++){
                dp[i] = false;
                for(int j=0;j<i;j++){
                    if(dp[j] && j+nums[j]>=i){
                        dp[i] = true;
                        break;
                    }
                }
            }
            return dp[n-1];
        }

        // 贪心算法 时间复杂度O(n) 空间复杂度O(1)
        // 从前往后遍历，每次更新最远能到达的位置
        bool canJump(vector<int>& nums) {
            int n = nums.size();
            int rightmost = 0;
            for(int i=0;i<n;i++){
                if(i<=rightmost){
                    rightmost = max(rightmost, i+nums[i]);
                    if(rightmost>=n-1){
                        return true;
                    }
                }
            }
            return false;
        }

        // 逆向思维，从后往前遍历
        bool canJump3(vector<int>& nums) {
            int n = nums.size();
            int last = n-1;
            for(int i=n-2;i>=0;i--){
                if(i+nums[i]>=last){
                    last = i;
                }
            }
            return last==0;
        }
    };

int main() {
    Solution solution;
    vector<int> nums = {2,3,1,1,4};
    bool result = solution.canJump(nums);
    cout<<result<<endl;
    return 0;
}