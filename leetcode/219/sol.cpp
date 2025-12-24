#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            int n =nums.size();
            unordered_map<int, int> map;
            for(int i=n-1;i>=0;i--){
                if(map.count(nums[i])){
                    if(map[nums[i]] - i <= k){
                        return true;
                    }else{
                        map[nums[i]] = i;
                    }
                } else{
                    map[nums[i]] = i; // 索引
                }
            }
            return false;
        }
    };