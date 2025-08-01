
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include<unordered_set>
using namespace std;

// 同样可以学习一下官解，自己的解法是暴力
class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            unordered_set<int> zero_row;
            unordered_set<int>zero_col;
            int m=matrix.size(),n=matrix[0].size();
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(matrix[i][j]==0){
                        zero_row.insert(i);
                        zero_col.insert(j);
                    }
                }
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(zero_col.find(j)!=zero_col.end()||zero_row.find(i)!=zero_col.end()){
                        matrix[i][j]=0;
                    }
                }
            }
        }
    };