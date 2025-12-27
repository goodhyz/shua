#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // 二维dp，其中每个节点只上一行和上一列相关，所以可以使用滚动数组进行进行优化
  bool isInterleave(string s1, string s2, string s3) {
    int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
    if (l1 + l2 != l3)
      return true;
    vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1, false));
    dp[0][0] = true;
    for (int i = 1; i < l1 + 1; i++) {
      dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
    }
    for (int j = 1; j < l2 + 1; j++) {
      dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
    }
    for (int i = 1; i < l1 + 1; i++) {
      for (int j = 1; j < l2 + 1; j++) {
        dp[i][j] = (dp[i][j - 1] && s3[i + j - 1] == s2[j - 1]) ||
                   (dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]);
      }
    }
    return dp[l1][l2];
  }

  bool isInterleave1(string s1, string s2, string s3) {
    int l1 = s1.size(), l2 = s2.size(), l3 = s3.size();
    if (l1 + l2 != l3)
      return false;
    vector<bool> dp(l2 + 1, false);
    dp[0] = true;
    for(int i=0;i<l1+1;i++){
        for(int j=0;j<l2+1;j++){
            if(i>0){
                dp[j] = dp[j] && (s1[i-1] == s3[i+j-1]);
            }
            if(j>0){
                dp[j] = dp[j] || (dp[j-1] && s2[j-1] == s3[i+j-1]);
            }
        }
    }
    return dp[l2];
  }
};