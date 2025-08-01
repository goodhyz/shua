#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,0);
        int pre =0,ans = nums[0];
        for(int i=0;i<n;i++){
            pre = max(pre+nums[i],nums[i]);
            ans = max(ans,pre);
        }
        return ans;
    }
};