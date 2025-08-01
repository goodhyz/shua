#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int candy(vector<int> &ratings) {
        int n = ratings.size(), sum = 1;
        int dec = 0, inc = 0;
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
                dec = 0;
                inc = candies[i] - 1; // 易错点 函数中无法判断“上一段增序列”是否结束
                sum += candies[i];
            } else if (ratings[i] == ratings[i - 1]) {
                candies[i] = 1;
                dec = 0;inc = 0;
                sum += candies[i];
            } else {
                dec++;
                if (dec-1 == inc) { // 利用上一段增序列 与 本段减序列的关系 ，使用后重置 ，但需要考虑如果没用上的话如何重置
                    dec++;
                    // inc = 0;
                }
                sum += dec;
            }
        }
        return sum;
    }
 int candy2(vector<int>& ratings) {
        int n = ratings.size();
        int ret = 1;
        int inc = 1, dec = 0, pre = 1;
        cout<<1<<" ";
        for (int i = 1; i < n; i++) {
            if (ratings[i] >= ratings[i - 1]) {
                dec = 0;
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
                ret += pre;
                inc = pre;
                cout<< pre<<" ";
            } else {
                dec++;
                if (dec == inc) {
                    dec++;
                }
                ret += dec;
                pre = 1;
                cout<<dec<<" ";
            }
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> ratings = {58,21,72,77,48,9,38,71,68,77,82,47,25,94,89,54,26,54,54,99,64,71,76,63,81,82,60,64,29,51,87,87,72,12,16,20,21,54,43,41,83,77,41,61,72,82,15,50,36,69,49,53,92,77,16,73,12,28,37,41,79,25,80,3,37,48,23,10,55,19,51,38,96,92,99,68,75,14,18,63,35,19,68,28,49,36,53,61,64,91,2,43,68,34,46,57,82,22,67,89};
    // vector<int> ratings 2  1  2  3  2  1  2 3  1  2  3  2  1  2  1  3  4
    // solution.candy2(ratings);
    // cout<<endl;
    cout << solution.candy(ratings) << endl;
    return 0;
}