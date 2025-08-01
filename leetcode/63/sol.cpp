#include<vector>
using namespace std;

class Solution {
    public:
        int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid) {
            int m=obstacleGrid.size(),n=obstacleGrid[0].size();
            if(obstacleGrid[m-1][n-1]==1)return 0;
            vector<vector<int>> dp(m,vector<int>(n,0));
            dp[0][0]=1;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(obstacleGrid[i][j]==0){
                        if(i-1>=0)dp[i][j]+=dp[i-1][j];
                        if(j-1>=0)dp[i][j]+=dp[i][j-1];
                    }
                }
            }
            return dp[m-1][n-1];
        }

        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m=obstacleGrid.size(),n=obstacleGrid[0].size();
            vector<vector<int>> dp(m,vector<int>(n,0));
            for(int i=0;i<m;i++){
                if(obstacleGrid[i][0]==1){
                    break;
                }
                dp[i][0]=1;
            }
            for(int i=0;i<n;i++){
                if(obstacleGrid[0][i]==1){
                    break;
                }
                dp[0][i]=1;
            }
            for(int i=1;i<m;i++){
                for(int j=1;j<n;j++){
                    if(obstacleGrid[i][j]==0){
                        dp[i][j]=dp[i-1][j]+dp[i][j-1];
                    }
                }
            }
            return dp[m-1][n-1];
        }
    };