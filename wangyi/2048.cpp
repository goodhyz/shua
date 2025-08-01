#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void print_matrix(vector<vector<int>> &matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j];
            if (j + 1 == n) {
                cout << endl;
            } else {
                cout << " ";
            }
        }
    }
}
void change_line(vector<int> &line) {
    // 默认往左
    if (line.size() == 1)
        return;
    int l = 0, r = 1;
    while (r < line.size()) {
        if (l == r)
            r++;
        if (line[l] == 0) { // l为0的情况 一定会把非零的移到左边
            line[l] = line[r];
            line[r] = 0;
            r++;
        } else { // 不为0
            if (line[l] == line[r]) {
                if (line[l] != 2048) {
                    line[l] = 2 * line[l];
                    line[r] = 0;
                    l++;
                    r++;
                } else { // 处理2048的特殊情况
                    l++;
                }
            } else {
                if (line[r] == 0) {
                    r++;
                }else{
                    l++;
                }
            }
        }
    }
}
void change_matrix(vector<vector<int>> &matrix, int opera_id) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> col(m, 0);
    switch (opera_id) {
    case 0: // 上
        /* code */
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                col[i] = matrix[i][j];
            }
            change_line(col);
            for (int i = 0; i < m; i++) {
                matrix[i][j] = col[i];
            }
        }
        break;
    case 1: // 左
        for (int i = 0; i < m; i++) {
            change_line(matrix[i]);
        }
        break;
    case 2: // 下
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                col[i] = matrix[n - 1 - i][j];
            }
            change_line(col);
            for (int i = 0; i < m; i++) {
                matrix[n - 1 - i][j] = col[i];
            }
        }
        break;
    case 3: // 右
        for (int i = 0; i < m; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
            change_line(matrix[i]);
            reverse(matrix[i].begin(), matrix[i].end());
        }
        break;
    default:
        break;
    }
}
int main() {
    int T, len, m, n;
    cin >> T; // T组数据
    while (T--) {
        cin >> len;
        vector<int> opera(len);
        for (int i = 0; i < len; i++) {
            cin >> opera[i];
        }
        // 0 1 2 3 上 左 下 右
        cin >> m >> n;
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        for (int i = 0; i < len; i++) {
            // 操作matrix
            change_matrix(matrix, opera[i]);
            cout<<"======"<<endl;
            print_matrix(matrix, m, n);
        }
        // 输出matrix
        // cout<<"======"<<endl;
        // print_matrix(matrix, m, n);
    }
}
// 64 位输出请用 printf("%lld")