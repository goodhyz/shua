#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    //这种写法也没问题
    /*
     vector<string> summaryRanges(vector<int> &nums) {
         vector<string> res;
         if(nums.size()==0)return res;
         int start_idx,end_idx=0;
         while(end_idx<nums.size()){
             if(end_idx + 1 < nums.size() &&nums[end_idx+1]==nums[end_idx]+1){
                 end_idx++;
             }else{
                 if(start_idx==end_idx){res.push_back(to_string(nums[start_idx]));}
                 else{
                     res.push_back(to_string(nums[start_idx])+"->"+to_string(nums[end_idx]));
                 }
                 start_idx=++end_idx;
             }
         }
         return res;
     }*/
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> res;
        if (nums.size() == 0)
            return res;
        int start_idx, end_idx = 0;
        while (end_idx < nums.size()) {
            start_idx = end_idx;
            // 分组循环，这组循环结束后，一定可以赋值
            while (end_idx + 1 < nums.size() && nums[end_idx + 1] == nums[end_idx] + 1) {
                end_idx++;
            }
            if (start_idx == end_idx) {
                res.push_back(to_string(nums[start_idx]));
            } else {
                res.push_back(to_string(nums[start_idx]) + "->" + to_string(nums[end_idx]));
            }
            end_idx++;
        }
        return res;
    }
};