#include <cmath>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> set(nums.begin(),nums.end());
    int ans=0;
    for(auto num: nums){
        if(set.count(num-1)){
            continue;
        }
        int len=1;
        while(set.count(++num)){
            len++;
        }
        ans = max(ans,len);
    }
    return ans;
  }
};