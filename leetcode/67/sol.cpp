#include <string>

using namespace std;

class Solution {
  public:
    string addBinary(string a, string b) {
        string res;
        int size_a = a.size() - 1, size_b = b.size() - 1;
        int carry = 0, sum;
        while (size_a >= 0 || size_b >= 0) {
            sum = (size_a >= 0 ? a[size_a] : '0') + (size_b >= 0 ? b[size_b]: '0') - 2 * '0' + carry;
            carry = sum / 2;
            sum = sum % 2;
            res.insert(0, 1, sum + '0');
            size_a--, size_b--;
        }
        if(carry)res.insert(0, 1, '1');
        return res;
    }
};

int main() {
    Solution s;
    s.addBinary("11", "1");
    printf("%s", s.addBinary("11", "1"));
}