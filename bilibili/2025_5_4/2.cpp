#include <bits/stdc++.h>

using namespace std;

class solution {
  private:
    queue<char> qa, qb, qc;

  public:
    string GetShortest(string a, string b, string c) {
        for (auto _a : a) {
            qa.push(_a);
        }
        for (auto _b : b) {
            qb.push(_b);
        }
        for (auto _c : c) {
            qc.push(_c);
        }

    }
};
int main() {
    string a, b, c;
    cin >> a >> b >> c;
    int total = a.size() + b.size() + c.size();
    return total - 2;
}