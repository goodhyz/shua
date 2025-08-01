#include <iostream>
using namespace std;

int main() {
    long a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    for (int x = 0; x <= 2500; x++) {
        for (int y = 0; y <= 2500; y++) {
            for (int z = 0; z <= 2500; z++) {
                if ((-1 * (a * x + b * y + c * z - n)) % (d) == 0) {
                    continue;
                }
                int w = (a * x + b * y + c * z - n) / (-d);
                if (0 <= w && w <= 2500) {
                    cout << x << " " << y << " " << z << " " << w << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1;
}
// 64 位输出请用 printf("%lld")