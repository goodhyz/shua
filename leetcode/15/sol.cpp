#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end()); // 默认升序-2 -1 0 1 2
        vector<int> ans;
        vector<vector<int>> res;
        int l1 = 0, l2 = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++) {
            // 写法如下在某些编译器中无法运行
            // if(i>0 && nums[i]==nums[i-1]){
            //     continue;
            // }
            if (i > 0) { // 第一个条件错误 直接返回 (短路求值)
                if (nums[i] == nums[i - 1])
                    continue;
            }
            int target = -nums[i];
            l1 = i + 1;
            l2 = nums.size() - 1;
            while (l1 < l2) {
                if (l1 != i + 1) {
                    if (nums[l1] == nums[l1 - 1]) {
                        l1++;
                        continue;
                    }
                }
                // if(l1!=i+1 && nums[l1]==nums[l1-1]){
                //     l1++;continue;
                // }
                if (nums[l1] + nums[l2] < target) {
                    l1++;
                } else if (nums[l1] + nums[l2] > target) {
                    l2--;
                } else {
                    res.push_back({nums[i], nums[l1], nums[l2]});
                    l1++;
                    l2--;
                    continue;
                }
            }
        }
        // for (auto answer : res) {
        //     for (auto elem : answer) {
        //         cout << elem << " ";
        //     }
        //     cout << endl;
        // }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    // -4 -1 -1 0 1 2
    s.threeSum(nums);
}