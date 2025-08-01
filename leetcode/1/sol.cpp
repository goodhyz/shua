#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:

    // 先排序后查找，时间复杂度o(nlogn) 空间复杂度o(n)
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> indices(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            indices[i] = i;
        }

        // 按照元素值排序索引数组
        sort(indices.begin(), indices.end(), [&nums](int a, int b) {
            return nums[a] < nums[b];  // 比较nums数组中的元素值
        });
        int l1 = 0, l2 = nums.size()-1;
        while (l1 < l2) {
            if (nums[indices[l1]] + nums[indices[l2]] < target)
                l1++;
            else if (nums[indices[l1]] + nums[indices[l2]] > target)
                l2--;
            else
                break;
        }
        return {indices[l1], indices[l2]};
    }

    // 使用hash表，存储已经访问的元素及其下标 时间复杂度o(n) 空间复杂度o(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }

};


int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution s;
    s.twoSum(nums,target);
}