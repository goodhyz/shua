#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
int max_price(vector<float> &today, vector<float> &tomorrow, float k) {
    // 返回最大收益的一支股票，没有则返回-1
    int size = today.size();
    float max_profit = 0;
    int max_idx = -1;
    for (int i = 0; i < size; i++) {
        float profit = (k / today[i]) * (tomorrow[i] - today[i]);
        if (profit > max_profit) {
            max_idx = i;
            max_profit = profit;
        }
    }
    return max_idx;
}
int main() {
    int n, m;
    float k; // n天 m支 k元
    cin >> n >> m >> k;
    vector<vector<float>> prices(n, vector<float>(m, 0.0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> prices[i][j];
        }
    }
    vector<vector<int>> res(n, vector<int>(2, -1));
    int idx_purchased = -1; // 第一天还没买股票
    // 查询每一天
    for (int i = 0; i < n - 1; i++) {
        res[i][0] = idx_purchased; // 卖掉上一份股票;
        // 收益
        if (idx_purchased != -1) {
            k += (k / prices[i - 1][idx_purchased]) * (prices[i][idx_purchased] - prices[i - 1][idx_purchased]);
        }
        idx_purchased = max_price(prices[i], prices[i + 1], k);
        res[i][1] = idx_purchased;
    }
    res[n - 1][0] = idx_purchased;
    if (idx_purchased != -1) {
        k += (k / prices[n - 2][idx_purchased]) * (prices[n - 1][idx_purchased] - prices[n - 2][idx_purchased]);
    }
    res[n - 1][1] = -1;

    cout << fixed << setprecision(4) << k << endl;
    for (int i = 0; i < n; i++) {
        cout << res[i][0] << " " << res[i][1];
        if (i < n - 1)
            cout << endl;
    }
}
// 64 位输出请用 printf("%lld")

// 5 5 100
// 3.0 1.0 5.0 7.0 4.0 // 第i 天
// 2.0 4.0 6.0 4.0 7.0 // 第 i
// 8.0 3.0 9.0 3.0 5.0
// 10.0 4.0 8.0 6.0 9.0
// 3.0 8.0 10.0 5.0 6.0