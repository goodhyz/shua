class Solution {
    public:
        int climbStairs(int n) {
            if(n==1)return 1;
            if(n==2)return 2;
            vector<int>dp(2);
            dp[0]=1;dp[1]=2;
            for(int i=2;i<n;i++){
                int t=dp[1];
                dp[1]=dp[0]+dp[1];
                dp[0]=t;
            }
            return dp[1];
        }
    };