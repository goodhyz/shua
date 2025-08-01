#include <iostream>
#include <sstream>
#include <string>

using namespace std;
class Solution {
  public:
    int minres(int guest, int candy, int purchase) {
        // n张券最少需要购买[n*(k+1)/2,n*3(k+1)/2)
        // 不用券购买力为 (0,(k+1)/2)
        int maxCandyWithoutTicket = (purchase + 1) / 2 - 1;
        if (maxCandyWithoutTicket * guest >= candy) {
            return 0;
        }
        candy -= maxCandyWithoutTicket * guest; // 白嫖后
        // 贪心，计算从0-guest 张券最多能购买多少candy 此时一张券最多买k个糖果
        int ticket;
        ticket = candy/purchase;
        if(candy%purchase)ticket++;
        // if (candy % purchase)
        //     ticket++;
        return ticket;
    }
};


// int main() {
//     int T, n, m, k;
//     cin >> T;
//     Solution s;
//     while (T--) {
//         cin >> n >> m >> k;
//         cout << s.minres(n, m, k) << endl;
//     }
// }
int main(){
    int n=3;
    int m=300;
    int k=100;
    Solution s;
    cout<<s.minres(n,m,k)<<endl;
}