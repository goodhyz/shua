#include <iostream>
#include <sstream>
#include <string>

using namespace std;
class Solution {
  public:
    string isLucky(string path, int n) {
        if (n < 9) {
            return "unlucky";
        }
        int max_count = 0, count = 0;
        for (int i = 0; i < n; i++) {
            if (path[i] == '1')
                count++;
            else if (count > 9) {
                return "unlucky";
            } else {
                max_count = max(count, max_count);
                count = 0;
            }
        }
        if (max_count == 9)
            return "lucky";
        return "unlucky";
    }
};

int main() {
    int T, n;
    cin >> T;
    Solution s;
    while (T--) {
        string path;
        cin >> n >> path;
        cout << s.isLucky(path, n) << endl;
    }
}