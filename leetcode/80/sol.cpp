#include <iostream>
#include <vector>

using namespace std;
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        // 双指针
        int p1 = 0, p2 = 1;
        int len = nums.size(), count = 1;
        if (len < 2)
            return len;
        while (p2 < nums.size()) {
            if (nums[p1] == nums[p2]) {
                count++;
                if (count <= 2) {
                    nums[p1 + 1] = nums[p2];
                    p1++;
                } else {
                    len--;
                }
            } else {
                nums[p1 + 1] = nums[p2];
                p1++;
                count = 1;
            }
            p2++;
        }
        return len;
    }
};

class Solution1 {
    public:
        int removeDuplicates(vector<int>& nums) {
            int size =nums.size();
            if(size<2){
                return size;
            }
            int l1 = 2,l2=2;
            while(l2<size){
                if(nums[l1-2]!=nums[l2]){
                    nums[l1]=nums[l2];
                    l1++;
                }
                l2++;
            }
            return l1;
        }
    };

// 补充主函数
int main() {
    Solution s;
    vector<int> nums = {0,0,1,1,1,1,2,3,3};
    int len = s.removeDuplicates(nums);
    cout << len << endl;
    for (int i = 0; i < len; i++) {
        cout << nums[i] << ' ';
    }
    return 0;
}