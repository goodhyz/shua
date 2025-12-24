#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    // 双指针
    int _trap(vector<int> &height) {
        int left = 0, right = 1;
        if(height.size() <3) return 0; // 易错点 边界条件
        int total = 0;
        while (right < height.size()) {
            if (height[right] >= height[left]) {
                for (int i = left + 1; i < right; i++) {
                    total += height[left] - height[i];
                }
                left = right;
                right++;
            } else {
                right++;
            }
        }
        int bound = left;
        right = height.size() - 1;
        left = right - 1;
        while (left >= bound) {
            if (height[left] >= height[right]) {
                for (int i = right - 1; i > left; i--) {
                    total += height[right] - height[i];
                }
                right = left;
                left--;
            } else {
                left--;
            }
        }
        return total;
    }

    int trap(vector<int> &height) {
        int n = height.size();
        vector<int> leftMax(n,0), rightMax(n,0);
        leftMax[0] = height [0];
        for(int i=1;i<n;i++){
            leftMax[i] = max(leftMax[i-1],height[i]);
        }
        rightMax[n-1] = height[n-1];
        for(int i = n-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1],height[i]);
        }
        int total = 0;
        for(int i=1;i<n-1;i++){
            total += min(rightMax[i],leftMax[i])- height[i];
        }
        return total;
    }
};

int main() {
    Solution solution;
    vector<int> height = {0,0,0};
    cout << solution.trap(height) << endl;
    return 0;
}