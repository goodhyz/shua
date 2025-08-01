#include <vector>

using namespace std;

class Solution {
  public:
    // 二分，一定有一段是升序
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1, mid;
        // 找到无序的索引
        while (l <= r) {
            mid = l + (r - l) / 2;
            if(nums[mid]<nums[r]){//右边有序 目标在l 到 mid
                r = mid;
            }else{// 左边有序 右边无序 目标一定在mid+1 到 r
                l=mid+1;
            }
        }
        return nums[r];
    }
};

// 7 8 1 2