#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  // 找规律做法
  string convert1(string s, int numRows) {
    string res;
    if (numRows == 1)
      return s;
    int t = 2 * numRows - 2;
    for (int row = 0; row < numRows; row++) {
      for (int i = row; i < s.size(); i += t) {
        // cout << s[i];
        res += s[i];
        if (row > 0 && row < numRows - 1 && i + t - 2 * row < s.size()) {
          // cout << s[i + 2 * numRows - 2- row];
          res += s[i + t - 2 * row];
        }
      }
    }
    return res;
  }
  // 直接遍历
  string convert(string s, int numRows) {
    int n=s.size();
    if(numRows==1 or numRows >n){
        return s;
    }
    vector<string> res(numRows);
    int t = numRows*2-2;

    for(int i=0,row=0;i<n;i++){
        res[row].push_back(s[i]);
        if(i%t < numRows-1){
            row++;
        }else{
            row--;
        }
    }
    string ans;
    for(auto str: res){
        ans+=str;
    }
    return ans;
  }
};

int main() {
  Solution s;
  string str = "LEETCODE";
  string out = "PAHNAPLSIIGYIR";
  cout << s.convert(str, 3) << endl;
  return 0;
}