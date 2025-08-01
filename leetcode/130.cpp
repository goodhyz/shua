#include<vector>
using namespace std;

class Solution {
    public:
        void solve(vector<vector<char>>& board) {
            int m =board.size(),n=board[0].size();
            for(int i=0;i<m;i++){
                dfs(board,i,n-1);
                dfs(board,i,0);
            }
            for(int j =1;j<n-1;j++){
                dfs(board,0,j);
                dfs(board,m-1,j);
            }
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]=='M'){board[i][j]='O';continue;};
                    if(board[i][j]=='O'){board[i][j]='X';continue;};//先赋值回O，不跳出会错误赋值
                }
            }
        }
    
    
       void dfs(vector<vector<char>>& board,int row,int col){
            if(row<0||col<0||row>=board.size()||col>=board[0].size()||board[row][col]!='O')return;//条件是!='O'，设置为=='X'会爆栈
            if(board[row][col]=='O')board[row][col]='M';
            dfs(board,row-1,col);
            dfs(board,row,col-1);
            dfs(board,row+1,col);
            dfs(board,row,col+1);
        } 
        
    };

    int main(){
        vector<vector<char>> board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
        Solution s;
        s.solve(board);
    }