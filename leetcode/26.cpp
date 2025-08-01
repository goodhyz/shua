#include<vector>
#include<iostream>

using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //双指针
        int p1=0,p2=1;
        int len = nums.size();
        if(len<2)return len;
        while(p2<nums.size()){
            if(nums[p1]==nums[p2]){
                len--;
            }else{
                nums[p1+1]=nums[p2];
                p1++;//只需要将p1++就好，不用p1=p2
            }
            p2++;
        }
        return len;
    }
};

//补充主函数
int main(){
    Solution s;
    vector<int> nums = {1,1,2};
    cout<<s.removeDuplicates(nums)<<endl;
    for(int num:nums){
        cout<<num<<' ';
    }
    return 0;
}