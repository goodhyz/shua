#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 注意审题， 是大于等于！ 不是等于 
class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int l1 = 0, l2 = 0;
        int sum = nums[l2];
        int min_length = INT_MAX;
        while (l2 < nums.size()) {
            if (sum < target) {
                l2++;
                if(l2 == nums.size())break; // 易错点
                sum+=nums[l2];
                // else l2--;
            } else if (sum >= target) {
                min_length=min(min_length,l2-l1+1);
                sum-=nums[l1];
                l1++;
            }
        }
        return min_length == INT_MAX ? 0 : min_length;
    }
    int minSubArrayLen2(int target, vector<int> &nums) {
        int l1 = 0, l2 = 0; // 初始化 l2 为 0
        int sum = 0;
        int min_length = INT_MAX; // 使用 INT_MAX 来初始化最小长度
        while (l2 < nums.size()) {
            sum += nums[l2];        // 累加 l2 指向的元素
            while (sum >= target) { // 当和满足目标时，尝试缩小窗口
                min_length = min(min_length, l2 - l1 + 1);
                sum -= nums[l1]; // 收缩窗口
                l1++;
            }
            l2++; // 移动 l2
        }
        return min_length == INT_MAX ? 0 : min_length;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1,1,1,1,1,1};
    int target = 11;
    cout << s.minSubArrayLen(target, nums);
}