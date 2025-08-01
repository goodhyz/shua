#include <vector>
#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
    vector<vector<int>> dp1(n, vector<int>(n, INT_MAX));
    // 0 0 start 向右或向下
    dp[0][0] = grid[0][0];
    dp1[n-1][n-1] = grid[n-1][n-1];
    for (int i = 1; i < n; i++)
    {
        if (grid[i][0] != 0 && dp[i-1][0] != INT_MAX)
        {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        if (grid[0][i] != 0 && dp[0][i-1] != INT_MAX)
        {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }
    }

    for(int i=n-2;i>=0;i--){
        if(grid[i][n-1]!=0 && dp1[i+1][n-1]!=INT_MAX){
            dp1[i][n-1] = dp1[i+1][n-1] + grid[i][n-1];
        }
        if(grid[n-1][i]!=0 && dp1[n-1][i+1]!=INT_MAX){
            dp1[n-1][i]=dp1[n-1][i+1] + grid[n-1][i];
        }
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j]!=0){
                if(dp[i][j-1]!=INT_MAX){
                    dp[i][j] = min(dp[i][j],dp[i][j-1]+grid[i][j]);
                }
                if(dp[i-1][j]!=INT_MAX){
                    dp[i][j] = min(dp[i][j],dp[i-1][j]+grid[i][j]);
                }
            }
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            if(grid[i][j]!=0){
                if(dp1[i][j+1]!=INT_MAX){
                    dp1[i][j] = min(dp1[i][j],dp1[i][j+1]+grid[i][j]);
                }
                if(dp1[i+1][j]!=INT_MAX){
                    dp1[i][j] = min(dp1[i][j],dp1[i+1][j]+grid[i][j]);
                }
            }
        }
    }
    int ret,res=INT_MAX;
    // 找一对相邻的数，使得两者之和相加为最小，取两者最大值为返回值
    // 上下方向
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j]!=INT_MAX && dp1[i+1][j]!=INT_MAX){ 
                int new_res = dp[i][j]+ dp1[i+1][j];
                if(new_res <=res) {
                    //cout<<i<<" "<<j<<endl;
                    res  = new_res;
                    int new_ret = max(dp[i][j],dp1[i+1][j]);
                    ret = min(ret,new_ret);
                }
            }
        }
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(dp[i][j]!=INT_MAX && dp1[i][j+1]!=INT_MAX){
                int new_res = dp[i][j]+ dp1[i][j+1];
                if(new_res <=res) {
                    //cout<<i<<" "<<j<<endl;
                    res  = new_res;
                    int new_ret = max(dp[i][j],dp1[i][j+1]);
                    ret = min(ret, new_ret);
                }
            }
        }
    }
    cout<< ret;
    
}
