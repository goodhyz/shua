#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int rob(vector<int> &nums) {
        size_t size = nums.size();
        if(size==0)return 0;
        if(size==1)return nums[0];
        if(nums[1]<nums[0])nums[1]=nums[0];
        // vector<int> dp(0,size);
        for(int i = 2;i < size;i++) {
            nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
        }
        return nums[size-1];
    }
};

int main(){
    vector<int> nums={8,1,1,8};
    Solution s;
    cout<<s.rob(nums)<<endl;
}