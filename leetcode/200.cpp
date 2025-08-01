#include<string>
#include<stack>
#include<vector>

using namespace std;

class Solution {
    private:

    public:
        int numIslands(vector<vector<char>>& grid) {
            int m=grid.size(),n=grid[0].size();
            int count =0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]=='1'){
                        dfs(grid,i,j);
                        count++;
                    }
                }
            }
            return count;
        }
        void dfs(vector<vector<char>>& grid,int row,int col){
            if(row<0||row>=grid.size()||col<0||col>=grid[0].size())return;
            if(grid[row][col]=='0'||grid[row][col]=='2')return;
            grid[row][col]='2';
            dfs(grid,row-1,col);
            dfs(grid,row,col-1);
            dfs(grid,row+1,col);
            dfs(grid,row,col+1);
            return;
        }
    };