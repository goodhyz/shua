#include <vector>

using namespace std;

class Solution {
  public:
    int removeElement(vector<int> &nums, int val) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            while (l <= r &&nums[l] != val) { //
                l++;
            }
            while (l <= r && nums[r] == val ) {
                r--;
            }
            if (l < r) {
                swap(nums[l], nums[r]);
            }
        }
        return r+1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1};
    s.removeElement(nums, 1);
}