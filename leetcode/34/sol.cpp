#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int n =nums.size();
        if(n==0)return vector<int> {-1,-1};
        int l1 = lower_bound(nums, target);
        if(l1==n|| nums[l1] != target){
            return vector<int> {-1,-1};
        }
        int l2 = lower_bound(nums, target+1) -1;
        if(nums[l2] != target){
            return vector<int> {-1,-1};
        }
        return vector<int> {l1,l2};
    }

    // 找第一个 大于等于 xx 的数
    int lower_bound(vector<int> &nums, int target) {
        int l = 0,r=nums.size()-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(nums[mid]>=target){
                r = mid-1;
            }else{
                l = mid+1;
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