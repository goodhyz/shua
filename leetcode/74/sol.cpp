#include <iostream>
#include<string>
#include<sstream>

#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n=matrix[0].size();
        int l=0,r=m*n-1,mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(matrix[mid/n][mid%n]>target){
                r=mid-1;
            }else if(matrix[mid/n][mid%n]<target){
                l=mid+1;
            }else{
                return true;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n=matrix[0].size();
        // 找upper_bound，最后一个小鱼等于targrt的数
        int row, l=0, r=m-1, mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(matrix[mid][0] > target){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        row = r;
        // 如果没有找到比target小的数
        if(row == -1)return false;
        // 在对应的行寻找
        l=0;r=n-1;
        while(l<=r){
            mid = l+(r-l)/2;
            if(matrix[row][mid] > target){
                r = mid-1;
            }else if(matrix[row][mid] < target){
                l = mid+1;
            } else{
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    string line;
    int m,n;
    cin>>m>>n;
    vector<vector<int>> matrix = vector<vector<int>>(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    cout<< s.searchMatrix(matrix, 13)<<endl;
}