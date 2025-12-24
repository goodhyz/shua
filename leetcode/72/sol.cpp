#include <string>
#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size(),l2=word2.size();
        // dp[i][j] word1 的前i个字符到 word2 的前j个字符的编辑距离
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
        for(int i=1;i<=l1;i++){
            dp[i][0] = i;
        }
        for(int j=1;j<=l2;j++){
            dp[0][j] = j;
        }
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = min(dp[i-1][j-1],1+min(dp[i-1][j],dp[i][j-1]));
                }else{
                    dp[i][j] = min(1+dp[i-1][j-1],1+min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        return dp[l1][l2];
    }
};