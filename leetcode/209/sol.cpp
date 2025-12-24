#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// 注意审题， 是大于等于！ 不是等于 
class Solution {
  public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int l=0,r=0,n=nums.size(),minLength=100001;
        long long sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                minLength = min(minLength,r-l);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return minLength == 100001? 0: minLength;
    }
};
int main() {
    Solution s;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 11;
    cout << s.minSubArrayLen(target, nums);
}