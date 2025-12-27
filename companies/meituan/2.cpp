#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
  private:
    int max_len;
    int count;

  public:
    Solution(int l) :max_len(l),count(0){}

    int findSub(vector<int> &nums) {
      int size = nums.size();
      if(nums.size()==1){
        return 1;
      }
      unordered_set <int> Set;
      for(int i=0;i<size;i++){
        Set.clear();
        for(int j=0;j<max_len&&i+j<size;j++){
          Set.insert(nums[i+j]);
          count+=check(Set,j+1);
        }
      }

      return count;

    }
    int check(unordered_set<int>& s,int len) {
      for(int i=1;i<=len;i++){
        if(s.count(i)==0){
          return 0;
        }
      }
      return 1;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums;
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++) {
            nums.push_back(j + 1);
        }
        max_len = max(num, max_len);
    }
    Solution s(max_len);
    cout<<s.findSub(nums);
}

// 64 位输出请用 printf("%lld")