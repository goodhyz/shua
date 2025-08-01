#include <string>
#include <vector>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
  public:
    bool wordBreak1(string s, vector<string> &wordDict) {
        unordered_set <string> set;
        for(const auto & word:wordDict){
            set.insert(word);
        }
        vector<bool> dp(s.size()+1);//dp[i]表示s的前i个字符是否由wordDict组成
        dp[0]=true;
        // 复杂度n 枚举wordDict
        for(int i=1;i<s.size()+1;i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&set.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> dp(s.size()+1);//dp[i]表示s的前i个字符是否由wordDict组成
        dp[0]=true;
        // 复杂度n 枚举wordDict
        for(int i=1;i<s.size()+1;i++){
            for(const auto& word:wordDict){
                int len = word.size();
                if(i>=len){
                    if(word == s.substr(i-len,len) && dp[i-len]){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    string s = "catsandog";
    vector<string> dic = {"cats", "dog", "sand", "and", "cat"};
    Solution so;
    cout<<so.wordBreak(s, dic);
}