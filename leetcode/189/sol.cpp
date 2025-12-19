#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // 1. 暴力解法, 需要额外的空间，
    // 空间复杂度O(n), 时间复杂度O(n)
    void rotate1(vector<int> &nums, int k) {
        int len = nums.size();
        k = k % len; // 错误点：k可能大于len，所以要取余
        vector<int> temp(k);

        for (int i = 0; i < k; i++) {
            temp[i] = nums[len - k + i];
        }
        for (int i = len - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
    // 2. 使用翻转
    // 尾部 k%n 个元素会到头部，所以第二次翻转k%n个，及[0,k%n)
    void rotate2(vector<int> &nums, int k) {
        int len = nums.size();
        k = k % len;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }

    // 3. 使用环状替换
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k% n;
        if(k==0)return;
        int count=0;
        for(int i=0;count<n;i++){
            int cur = i;
            int pre = nums[i];
            do { 
                int next = (cur+k)%n;
                swap(pre,nums[next]);
                cur = next;
                count++;
            } while(i != cur);
        }
    }

};

int main() {
    Solution solution;
    string line;
    getline(cin,line);
    stringstream ss(line);
    int n;
    vector<int> nums;
    while(ss>>n){
        nums.push_back(n);
    }
    solution.rotate(nums, 3);
    // for(auto num:nums){
    //     cout<<num<<endl;
    // }
    return 0;
}