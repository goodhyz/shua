#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int pre = -1, now;
    long long count = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0)
            pre = now;
        cin >> now;
        count += now;
        if (i >= 1) {
            if (pre > now) {
                count += now; //
            } else {
                count += pre - 1;
            }
        }
    }
    printf("%lld", count);
}
