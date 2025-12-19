#include<unordered_map>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    // 排序
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        return nums[n/2];
    }

    int majorityElement1(vector<int>& nums){
        unordered_map<int, int> map;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(map.count(nums[i])>0){
                map[nums[i]]++;
            }else{
                map[nums[i]]=1;
            }
            if(map[nums[i]]>n/2){
                return nums[i];
            }
        }
        return 0;
    }
};
// 还有很多种方法，比如排序，比如摩尔投票法，比如分治法，比如哈希表，比如随机化等等

int main() {
    vector<int> nums = {1,1,1,1,1,3,3};
    
}