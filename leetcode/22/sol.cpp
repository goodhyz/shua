#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> res;
  string tmp;
  vector<char> c_list;
  vector<string> generateParenthesis(int n) {
    c_list = {'(', ')'};
    backTrace(n, 0, 0);
    return res;
  }

  void backTrace(int n, int left, int right) {
    if (left < right) {
      return;
    }
    if (2*n == left + right) {
      if (left == right) {
        res.push_back(tmp);
      }
      return;
    }
    for (const char brace : c_list) {
      tmp.push_back(brace);
      if (brace == '(') {
        backTrace(n, left + 1, right);
      } else {
        backTrace(n, left, right + 1);
      }
      tmp.pop_back();
    }
  }
};

int main() {
  Solution s;
  vector<string> res = s.generateParenthesis(1);
  for (const auto &str : res) {
    cout << str << endl;
  }
}