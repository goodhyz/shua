#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
  public:
    int min_operation(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_count = 0;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
            } else {
                count = 1;
                max_count = max(count, max_count);
            }
        }
        return nums.size()-max_count;
    }
    int min_operation1(vector<int>& nums) {
        unordered_map<int, int> Map;
        int max_count = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (Map.count(nums[i])) {
                Map[nums[i]]++;
                max_count = max(max_count, Map[nums[i]]);
            } else {
                Map[nums[i]] = 1;
            }
        }
        return nums.size()-max_count;
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    Solution s;
    cout << s.min_operation1(nums);
}

// 64 位输出请用 printf("%lld")