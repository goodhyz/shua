#include <bits/stdc++.h>
using namespace std;


//多多有两个仅由正整数构成的数列s,和$2,多多可以对s,进行任意次操作,每次操作可以置换s中任意两个数字的位置.
//多多想让数列s 构成的数字尽可能大,但是小于82请问再经过任意次操作后,满足上述条件的数列s,构成的数字是多少


class Solution {
  public:
    // 要求s1尽可能大，但不能大过s2
    string max_num(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        sort(s1.begin(), s1.end());
        // 统计0的个数
        int start = 0;
        while (s1[start] == '0') {
            start++;
        }
        int len = len1 - start;
        if (len > len2) {
            return "-1";
        }
        if (len == len2 && s1[start] > s2[0]) {
            return "-1";
        }
        string res;
        // if (len < len2) {
        //     res = s1.substr(start, len + 1);
        //     reverse(res.begin(), res.end());
        //     return stoi(res);
        // }
        // 放len次
        start = 0;
        for (int idx = 0; idx < len; idx++) {
            bool found = false;
            for (int i = len1 - 1; i >= start; i--) {
                if (s1[i] == s2[idx]) {
                    res.push_back(s1[i]);
                    swap(s1[start], s1[i]);
                    start++;
                    sort(s1.begin()+start,s1.end());
                    found = true;
                    break;
                    // 直接返回
                } else if (s1[i] < s2[idx]) {
                    res.push_back(s1[i]);
                    swap(s1[start], s1[i]);
                    start++;
                    sort(s1.begin()+start,s1.end());
                    string res1 = s1.substr(start, len - idx);
                    reverse(res1.begin(), res1.end());
                    res += res1;
                    return res;
                }
            }
            if (found == false)
                return "-1";
        }
        return res;
    }
};

// int main() {
//     int T, n, m; // 分别为
//     string s1, s2;
//     cin >> T;
//     Solution s;
//     while (T--) {
//         cin >> n >> m;
//         cin >> s1 >> s2;
//         cout << s.max_num(s1, s2) << endl;
//     }
// }

int main() {
    string s1 = "101051";
    string s2 = "501721";
    Solution s;
    cout << s.max_num(s1, s2);
}
