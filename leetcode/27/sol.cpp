#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // int removeElement(vector<int>& nums, int val) {
    //     int n = nums.size();
    //     int l =0, r = n-1, k=n;
    //     while(l<=r){
    //         while(l<n && nums[l]!=val ){
    //             l++;
    //         }
    //         while(r>=0 && nums[r]==val){
    //             r--;
    //             k--;
    //         }
    //         if(l>r){
    //             break;
    //         }
    //         swap(nums[l],nums[r]);
    //     }
    //     return k;
    // }

    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int l =0, r = 0;
        while(r<n){
            if(nums[r] != val){
                nums[l++] = nums[r];
            }
            r++;
        }
        return l;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1};
    cout<< s.removeElement(nums, 1)<<endl;
}