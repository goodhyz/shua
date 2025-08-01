#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    private:
        vector<int> path;
        vector<vector<int>>res;
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            backTrace(candidates,target,0,0);
            return res;
        }
        void backTrace(vector<int>& candidates,int target,int sum,int idx){
            if(sum>target)return;
            for(int i=idx;i<candidates.size();i++){
                path.push_back(candidates[i]);
                backTrace(candidates,target,sum+candidates[i],i);
                path.pop_back();
            }
            if(sum==target)res.push_back(path);
        }
        
    };