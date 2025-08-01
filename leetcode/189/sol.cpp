#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // 1. 暴力解法, 需要额外的空间，
    // 空间复杂度O(n), 时间复杂度O(n)
    void rotate1(vector<int> &nums, int k) {
        int len = nums.size();
        k = k % len; // 错误点：k可能大于len，所以要取余
        vector<int> temp(k);

        for (int i = 0; i < k; i++) {
            temp[i] = nums[len - k + i];
        }
        for (int i = len - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
    // 2. 使用翻转
    void rotate2(vector<int> &nums, int k) {
        int len = nums.size();
        k = k % len;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    // 3. 使用环状替换
    void rotate3(vector<int> &nums, int k) {
        int len = nums.size();
        k = k % len;
        int count = 0;
        for (int start = 0; count < len; start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % len;
                swap(prev,nums[next]); // 复制给下一个位置，并保留下一个位置的值
                current = next;
                count++;
            } while (start != current);
        }
    }

};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    solution.rotate3(nums, 3);
    // for(auto num:nums){
    //     cout<<num<<endl;
    // }
    return 0;
}