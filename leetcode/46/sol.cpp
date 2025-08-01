#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
  private:
    vector<vector<int>> res;
    vector<int> path;
    unordered_set<int> pathElem;

  public:
    void backTrace(vector<int> &nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (auto &num : nums) {
            if (pathElem.count(num) == 0) {
                path.push_back(num);
                pathElem.insert(num);
                backTrace(nums);
                path.pop_back();
                pathElem.erase(num);
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums) {
        backTrace(nums);
        return res;
    }
};


// nums的左边是已经使用过的元素
// 降低空间复杂度，空间复杂度都在栈上
class Solution {
  private:
    vector<vector<int>> res;
    vector<int> path;

  public:
    void backTrace(vector<int>& nums,int start) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i=start;i<nums.size();i++){
            path.push_back(nums[i]);
            swap(nums[i],nums[start]);
            backTrace(nums,start+1);
            swap(nums[i],nums[start]);
            path.pop_back();
        }

    }
    vector<vector<int>> permute(vector<int> &nums) {
        backTrace(nums,0);
        return res;
    }
};
int main() {
    Solution s;
    vector<int> nums = {1, 2, 3};
    auto ans = s.permute(nums);
    for (auto it : ans) {
        for (auto num : it) {
            cout << num << " ";
        }
        cout << endl;
    }
}