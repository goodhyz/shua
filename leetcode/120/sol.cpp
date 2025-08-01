#include <vector>

using namespace std;

class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<int> dp(n, __INT_MAX__);
        dp[0] = triangle[0][0];
        for (int r = 1; r < n; r++) {
            for (int c = r; c >= 0; c--) { // 每一行的每一列
                if (c ==0) {
                    dp[c] = dp[c] + triangle[r][c];
                } else if (c == r) {
                    dp[c] = dp[c - 1] + triangle[r][c];
                } else {
                    dp[c] = min(dp[c - 1], dp[c]) + triangle[r][c];
                }
            }
        }
        int m = dp[0];
        for (int i = 1; i < n; i++) {
            if (m > dp[i])
                m = dp[i];
        }
        return m;
    }
};

int main() {
    Solution s;
    vector<vector<int>> in = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    s.minimumTotal(in);
}