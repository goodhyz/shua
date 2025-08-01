#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    int total = 0, min_num = 10000;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        min_num = min(nums[i], min_num);
        total += nums[i];
        nums[i] % 2 == 0 ? total-- : total;
    }
    if (n % 2 == 0) {
        total -= min_num % 2 == 0 ? min_num - 1 : min_num;
    }
    cout << total;
}