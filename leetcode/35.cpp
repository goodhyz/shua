#include<vector>

using namespace std;

class Solution {
    public:
        //找第一个大于等于xx的元素 就是lower bound
        int searchInsert(vector<int>& nums, int target) {
            int l=0,r=nums.size()-1,mid;
            // if(nums[r]<target)return r+1;
            while(l<=r){
                mid = l+(r-l)/2;
                if(nums[mid]>=target){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            return l;
        }
    };