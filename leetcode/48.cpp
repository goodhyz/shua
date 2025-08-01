#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//可以学习一下官阶，自己的思路实现起来比较慢
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n =matrix.size();
            int temp,rotate_num = n/2;
            for(int i=0;i<rotate_num;i++){ //第 i 圈旋转
                for(int j=0;j<n-2*i-1;j++){
                    // temp = matrix[i][i+j];
                    // matrix[i][i+j] = matrix [i+j][n-i-1];
                    // matrix [i+j][n-i-1]=matrix [n-i-1][n-i-1-j];
                    // matrix [n-i-1][n-i-1-j]=matrix[n-i-j-1][i];
                    // matrix[n-i-j-1][i] = temp;
                    temp = matrix[i][i+j];
                    matrix[i][i+j] = matrix[n-i-j-1][i];
                    matrix[n-i-j-1][i] = matrix [n-i-1][n-i-1-j];
                    matrix [n-i-1][n-i-1-j] =matrix [i+j][n-i-1];
                    matrix [i+j][n-i-1] = temp;
                }
            }
        }
    };

int main(){
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    int n=matrix.size();
    Solution s;
    s.rotate(matrix);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}