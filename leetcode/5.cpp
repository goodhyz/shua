#include <vector>
#include<string>
#include<iostream>

using namespace std;

class Solution {
  public:
    // 二维dp
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<2)return s;
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        for(int i=0;i<n;i++){
          dp[i][i]=true;
        }
        int max_len = 1;
        int start_pos = 0;

        // 更新状态，最重要的一步
        for(int L=2;L<=n;L++){
          for(int i = 0;i+L-1<n;i++){
            // 判断字符相等
            dp[i][i+L-1]= (s[i] == s[i+L-1]);
            if(i+1<=i+L-2){
              dp[i][i+L-1] =dp[i][i+L-1] && dp[i+1][i+L-2];
            }
            if(dp[i][i+L-1]){
              if(L>max_len){
                start_pos = i;
                max_len = L;
              }
            }

          }
        }

        return s.substr(start_pos,max_len);
    }
};
