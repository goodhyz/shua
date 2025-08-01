#include <bits/stdc++.h>
#include <cctype>
#include <cstdio>
using namespace std;

int main() {
    long long k;
    string str;
    cin >> str >> k;
    long long k_upper = k % 26;
    long long k_lower = (k * (k + 1) / 2) % 26;
    for (auto &c : str) {
        if (isupper(c)) { // 大写
            c -= k_upper;
            if (c < 'A') {
                c += 26;
            }
        } else if (islower(c)) { // 小写
            c += k_lower;
            if (c > 'z') {
                c -= 26;
            }
        }
    }
    cout << str << endl;
}
// 64 位输出请用 printf("%lld")