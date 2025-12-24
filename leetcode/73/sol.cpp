
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// 同样可以学习一下官解，自己的解法是暴力
class Solution {
public:
  //   void setZeroes(vector<vector<int>> &matrix) {
  //     int m = matrix.size(), n = matrix[0].size();
  //     // 空间复杂度 O(m+n)
  //     vector<bool> row(m,0),col(n,0);
  //     for (int i = 0; i < m; i++) {
  //       for (int j = 0; j < n; j++) {
  //         if (matrix[i][j] == 0) {
  //             row[i] = true;
  //             col[j] = true;
  //         }
  //       }
  //     }
  //     for (int i = 0; i < m; i++) {
  //       for (int j = 0; j < n; j++) {
  //         if (row[i] || col[j]) {
  //             matrix[i][j] = 0;
  //         }
  //       }
  //     }
  //   }

  void setZeroes(vector<vector<int>> &matrix) {
    int m =matrix.size(),n=matrix[0].size();
    bool zero_row_flag = false, zero_col_flag = false;
    for(int i=0;i<m;i++){
        if(matrix[i][0]==0){
            zero_col_flag = true;
            break;
        }
    }
    for(int j=0;j<n;j++){
        if(matrix[0][j]==0){
            zero_row_flag = true;
            break;
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(matrix[i][0] == 0 || matrix[0][j]==0){
                matrix[i][j] = 0;            
            }
        }
    }
    if(zero_col_flag){
        for(int i=0;i<m;i++){
            matrix[i][0] = 0;
        }
    }
    if(zero_row_flag){
        matrix[0] = vector<int>(n,0);
    }
  }
};