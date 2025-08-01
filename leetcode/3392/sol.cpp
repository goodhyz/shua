#include<vector>

using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count=0;
        for(int r=2;r<nums.size();r++){
            if(2*(nums[r]+nums[r-2])== nums[r-1]){
                count++;
            }
        }
        return count;
    }
};