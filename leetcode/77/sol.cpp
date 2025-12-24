#include <vector>

using namespace std;
class Solution {

private:
  vector<vector<int>> res;
  vector<int> path;

public:
  vector<vector<int>> combine(int n, int k) {
    backTrace(n, k, 1);
    return res;
  }

  void backTrace(int n, int k, int start) {
    if (path.size() == k) {
      res.push_back(path);
      return;
    }
    if (n - start + 1 < k - path.size()) {
      return;
    }
    for (int i = start; i <= n; i++) {
      path.push_back(i);
      backTrace(n, k, i + 1);
      path.pop_back();
    }
  }
};