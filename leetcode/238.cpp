#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

class Solution {
    public:
        // 关键点在于定义一个left和right，在一次遍历中分别记录当前元素左边的乘积和右边的乘积
        // 时间复杂度O(n)，空间复杂度O(n)
        vector<int> productExceptSelf(vector<int>& nums) {
            vector<int> res(nums.size(), 1);
            vector<int> left(nums.size(), 1);
            vector<int> right(nums.size(), 1);
            for(int i=0;i<nums.size();i++){
                if(i==0){
                    left[i] = 1;
                    right[nums.size()-1-i] = 1;
                }else{
                    left[i] = left[i-1]*nums[i-1];
                    right[nums.size()-1-i] = right[nums.size()-i]*nums[nums.size()-i];
                }
            }
            for(int i=0;i<nums.size();i++){
                res[i] = left[i]*right[i];
            }
            return res;
        }
    }; 