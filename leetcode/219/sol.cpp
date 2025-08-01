class Solution {
    public:
        bool containsNearbyDuplicate(vector<int>& nums, int k) {
            unordered_map<int,int> idx_map;
            for(int i=0;i<nums.size();i++){
                auto it = idx_map.find(nums[i]);
                if(it!=idx_map.end()){
                    if(i-idx_map[nums[i]]<=k)return true;
                    idx_map[nums[i]]=i;
                }else{
                    idx_map[nums[i]]=i;
                }
                /**
                if(it!=idx_map.end()&&i-idx_map[nums[i]]<=k){
                    return true;
                }else{
                    idx_map[nums[i]]=i;
                }
                 */
            }
            return false;
        }
    };