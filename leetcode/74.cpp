#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        // 两次二分
        int col, row, l, r, mid;
        // 先找行,第一个 **大于等于** target的数
        l = 0, r = m - 1;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (matrix[mid][n - 1] >= target) {
                r = mid - 1;
            } else if (matrix[mid][n - 1] < target) {
                l = mid + 1;
            }
        }
        row = l; 
        if(row == m)return false;
        if(matrix[row][n - 1] == target)return true;

        // 再找列
        l = 0, r = n - 1;
        while (l <= r) {
            col = l + (r - l) / 2;
            if (matrix[row][col] < target) {
                l = col + 1;
            } else if (matrix[row][col] > target) {
                r = col - 1;
            } else {
                return true;
            }
        }
        // cout << row << " " << col << endl;
        return false;
    }
};

int main() {
    Solution s;
    vector<vector<int>> m = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    s.searchMatrix(m, 13);
}