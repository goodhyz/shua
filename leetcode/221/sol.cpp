#include <iostream>
#include <vector>
using namespace std;

// 复杂度有点高
class Solution1 {
  public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int max_size = 0;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int size = 0;
                bool flag = true;
                while (flag) {
                    for (int k = 0; k <= size; k++) {
                        if (j + size >= n || k + i >= m || matrix[i + k][j + size] == '0') {
                            flag = false;
                            break;
                        }
                        if (k + j >= n || i + size >= m || matrix[i + size][j + k] == '0') {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                        size++;
                }
                max_size = max(size, max_size);
            }
        }
        return max_size * max_size;
    }
};

class Solution {
  public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int max_len = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp (m,vector<int>(n,0));
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == '1') {
                max_len = 1;
                dp[i][0]=1;
            }
        }
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == '1') {
                max_len = 1;
                dp[0][j]=1;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // matrix[i-1][j-1] matrix[i-1][j]  matrix[i][j-1]
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    int x = dp[i - 1][j - 1], y = dp[i - 1][j], z = dp[i][j - 1];
                    int min_c = (x < y ? x : y);
                    min_c = min_c < z ? min_c : z;
                    if (x > 0 && y > 0 && z > 0) {
                        dp[i][j] = min_c + 1;
                    }
                    max_len = max(dp[i][j], max_len);
                }
            }
        }
        return max_len * max_len;
    }
};

main() {
    Solution s;
    vector<vector<char>> matrix1 = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    vector<vector<char>> matrix = {{'1'}};
    vector<vector<char>> matrix2 = {{'1', '0'}, {'0', '1'}};
    cout << s.maximalSquare(matrix1);
}