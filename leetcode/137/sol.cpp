#include <vector>
#include<stdio.h>
using namespace std;

class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        vector<int> res(32, 0);
        for (const int &num : nums) {
            for (int i = 0; i < 32; i++) {
                res[31 - i] += num >> i & 1;
            }
        }
        int ans = 0;
        for (int i = 0; i <32; i++) {
            ans = ans << 1;
            ans += (res[i] % 3);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,1,0,1,0,1,99};
    printf("%i",s.singleNumber(nums));
}