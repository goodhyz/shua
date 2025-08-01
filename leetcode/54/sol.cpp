#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int **visit = new int *[m];
        for (int i = 0; i < m; i++) {
            visit[i] = new int[n]();
        }
        int row = 0, col = 0;
        visit[0][0] = 1;
        res.push_back(matrix[0][0]);
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direct_idx = 0;
        int *direct = directions[direct_idx];
        for (int i = 0; i < m * n - 1; i++) {
            if (row + direct[0] >= m || row + direct[0] < 0 || col + direct[1] < 0 || col + direct[1] >= n) {
                direct_idx = (direct_idx + 1) % 4;
                direct = directions[direct_idx];
            }
            // int change_nums = 0;
            while (visit[row + direct[0]][col + direct[1]] != 0) {
                direct_idx = (direct_idx + 1) % 4;
                direct = directions[direct_idx];
                // change_nums++;
                // if(change_nums==4)break;
            }
            // if(change_nums==4)break;
            row += direct[0];
            col += direct[1];
            res.push_back(matrix[row][col]);
            visit[row][col] = 1;
            continue;
        }

        for (int i = 0; i < m; i++) {
            delete[] visit[i];
        }
        delete[] visit;
        return res;
    }
    vector<int> spiralOrder1(vector<vector<int>> &matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> res;
        int **visit = new int *[m];
    
        // 动态分配并初始化访问数组
        for (int i = 0; i < m; i++) {
            visit[i] = new int[n]();
        }
    
        int row = 0, col = 0;
        visit[0][0] = 1;  // 标记访问过
        res.push_back(matrix[0][0]);
    
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direct_idx = 0;  // 初始方向为右（0, 1）
    
        // 用来控制循环直到所有元素都遍历
        for (int i = 1; i < m * n; i++) {
            int *direct = directions[direct_idx];  // 当前方向
            int next_row = row + direct[0];
            int next_col = col + direct[1];
    
            // 如果新的位置超出边界或者已访问过
            if (next_row >= m || next_row < 0 || next_col >= n || next_col < 0 || visit[next_row][next_col] == 1) {
                // 更改方向
                direct_idx = (direct_idx + 1) % 4; // 顺时针旋转方向
                direct = directions[direct_idx];
                next_row = row + direct[0];  // 重新计算新的行
                next_col = col + direct[1]; // 重新计算新的列
            }
    
            // 更新当前行列
            row = next_row;
            col = next_col;
    
            // 加入结果，并标记访问过
            res.push_back(matrix[row][col]);
            visit[row][col] = 1;
        }
    
        // 释放动态分配的内存
        for (int i = 0; i < m; i++) {
            delete[] visit[i];
        }
        delete[] visit;
    
        return res;
    }
    
};

int main() {
    Solution s;
    vector<vector<int>> matirx = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24}};
    vector<int> res = s.spiralOrder1(matirx);
    for (int elem : res) {
        cout << elem << " ";
    }
}