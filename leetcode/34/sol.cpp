#include <iostream>
#include <vector>
using namespace std;

// 二分查找一个while就能解决，没必要递归
// class Solution_bad {
//   public:
//     int binarySearch(vector<int> &nums, int target, int l, int r) {
//         if (l > r)
//             return -1;
//         int mid = l + (r - l) / 2;
//         if (nums[mid] == target) {
//             return mid;
//         } else if (nums[mid] < target) {
//             return binarySearch(nums, target, mid + 1, r);
//         } else {
//             return binarySearch(nums, target, l, mid - 1);
//         }
//         return -1;
//     }
//     vector<int> searchRange(vector<int> &nums, int target) {
//         int res = binarySearch(nums, target, 0, nums.size() - 1);
//         if (res == -1)
//             return vector<int>{-1, -1};
//         int l = res, r = res;
//         while (l >= 0 && nums[l] == target)
//             l--;
//         while (r < nums.size() && nums[r] == target)
//             r++;
//         return vector<int>{++l, --r};
//     }
// };

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int first, second;

        first = lower_bound(nums, target);
        if (first == nums.size()||nums[first] != target)
            return vector<int>{-1, -1};
        
        second = lower_bound(nums, target + 1) - 1;
        return vector<int>{first,second};
    }

    // 找第一个 大于等于 xx 的数
    int lower_bound(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1, mid, sec, first;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    auto res = s.searchRange(nums, 8);
    cout << res[0] << " " << res[1];
}