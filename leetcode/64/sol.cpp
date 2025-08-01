#include<vector>

using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> dp (m,vector(n,__INT_MAX__));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            dp[i][0]=grid[i][0]+dp[i-1][0];
        }
        for(int j=1;j<n;j++){
            dp[0][j] = grid[0][j]+dp[0][j-1];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j] = min(dp[i][j-1],dp[i-1][j])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};