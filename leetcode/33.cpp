#include <algorithm>
#include <vector>

using namespace std;

// 先找分割点再二分，但是复杂度高，可能还不如遍历
class Solution {
    public:
      int search(vector<int> &nums, int target) {
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
          int min = nums[r];
          int max = r>0?nums[(r-1)]:nums[nums.size()-1];
          if(target<min||target>max)return -1;
          int l1,r1;
          if(target<=nums[nums.size()-1]){// 在min 到最右中
              l1=r,r1=nums.size()-1;
          }else{
              l1=0,r1=r-1;
          }
          while(l1<=r1){
              mid = l1+(r1-l1)/2;
              if(nums[mid]<target){
                  l1=mid+1;
              }else if(nums[mid]>target){
                  r1 = mid -1;
              }else{
                  return mid;
              }
          }
          return -1;
      }
  };

class Solution1 {
    public:
        int search(vector<int>& nums, int target) {
            int l = 0, r = nums.size() - 1, mid;
            while (l <= r) {
                mid = l + (r - l) / 2;
                if(nums[mid]==target)return mid;

                if(nums[mid]>nums[r]){
                    if(target<nums[mid]&& target>nums[r]){
                        r=mid-1;
                    }else{
                        l=mid+1;
                    }
                }else{ // mid > nums[r] 右边无序
                    if(target>nums[mid]&& target<=nums[r]){
                        l=mid+1;
                    }else{
                        r=mid-1;
                    }
                }

            }
            return -1;
        }
    };


int main(){
    vector<int>nums={4,5,6,7,0,1,2};
    Solution1 s;
    s.search(nums,0);
}