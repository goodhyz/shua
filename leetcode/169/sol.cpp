#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashTable;
        int len = nums.size();
        for(auto num:nums){
            if(hashTable.find(num)!=hashTable.end()){
                hashTable[num]++;
            }else{
                hashTable[num]=1;
            }
            if(hashTable[num]>len/2)return num;
        }
        return 0;
    }

    int majorityElement1(vector<int>& nums){
        int candidate = 0,count=0;
        for(int i=0;i<nums.size();i++){
            if(count==0){
                candidate = nums[i];
                count=1;
            }else if(nums[i]==candidate){
                count++;
            }else{
                count--;
            }
        }
        return candidate;
    }
};
// 还有很多种方法，比如排序，比如摩尔投票法，比如分治法，比如哈希表，比如随机化等等