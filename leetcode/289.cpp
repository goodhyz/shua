
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include<unordered_set>
using namespace std;

class Solution {
    public:
        void gameOfLife(vector<vector<int>>& board) {
            vector<vector<int>> copy = board;
            int rows = board.size(),cols=board[0].size();
            int count;
            for(int row=0;row<rows;row++){
                for(int col=0;col<cols;col++){
                    count =0;
                    if((row-1>=0)&&copy[row-1][col]==1)count++;
                    if((row+1<rows)&&copy[row+1][col]==1)count++;
                    if((col+1<cols)&&copy[row][col+1]==1)count++;
                    if((col-1>=0)&&copy[row][col-1]==1)count++;
                    if((row-1>=0)&&(col-1>=0)&&copy[row-1][col-1]==1)count++;
                    if((row-1>=0)&&(col+1<cols)&&copy[row-1][col+1]==1)count++;
                    if((row+1<rows)&&(col+1<cols)&&copy[row+1][col+1]==1)count++;
                    if((row+1<rows)&&(col-1>=0)&&copy[row+1][col-1]==1)count++;
                    if(count<2||count>3)board[row][col]=0;
                    if((count==2||count==3)&&board[row][col]==1)board[row][col]=1;
                    if(count==3&&board[row][col]==0)board[row][col]=1;
                }
            }
        }
    };

int main(){
    Solution s;
    vector<vector<int>> board = {{1,1},{1,0}};
    s.gameOfLife(board);
}