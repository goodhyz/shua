#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        int n = l1 + l2;
        if (n % 2 == 0) {
            return (findKthNum(n / 2 - 1, nums1, nums2) + findKthNum(n / 2, nums1, nums2)) / 2.0;
        } else {
            return 1.0 * findKthNum(n / 2, nums1, nums2);
        }
    }
    // k为索引
    double findKthNum(int k, vector<int> &nums1, vector<int> &nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        int idx1 = 0, idx2 = 0;
        for (;;) {
            // 处理特殊情况
            if (l1 == idx1) {
                return nums2[idx2 + k];
            }
            if (l2 == idx2) {
                return nums1[idx1 + k];
            }
            if (k == 0) {
                return min(nums1[idx1], nums2[idx2]);
            }
            int newIdx1 = min(idx1 + (k+1) / 2-1, l1 - 1);
            int newIdx2 = min(idx2 + (k+1) / 2-1, l2 - 1);
            // 二分，做比较,排除小的
            if (nums1[newIdx1] >= nums2[newIdx2]) {
                k -= newIdx2 - idx2+1;
                idx2 = newIdx2+1;
            } else {
                k -= newIdx1 - idx1+1;
                idx1 = newIdx1+1;
            }
        }
    }
};

int main(){
    vector<int> nums1 = {1,3,4};
    vector<int> nums2 = {2,7,5};
    Solution s;
    cout<<s.findMedianSortedArrays(nums1,nums2);
}