#include <bits/stdc++.h>

using namespace std;

class Solution {
  private:
    vector<string> board;
    int res;
    vector<bool> isPlaced; // 每一行的放置情况
  public:
    // 是否可以放在i j,查看45度位置
    bool isDiagonal(int row, int col) {
        int n = board.size();
        for (int i = col - 1, bias = 1; i >= 0; i--, bias++) {
            if (row + bias < n && board[row + bias][i] == 'Q') {
                return false;
            }
            if (row - bias >= 0 && board[row - bias][i] == 'Q') {
                return false;
            }
        }
        return true;
    }
    int totalNQueens(int n) {
        string boardLine(n, '.');
        board = vector<string>(n, boardLine);
        isPlaced = vector<bool>(n, false);
        res = 0;
        backTrace(n, 0);
        return res;
    }
    void backTrace(int n, int idx) {
        if (idx == n) {
            res++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isPlaced[i]) {
                continue;
            } else if (isDiagonal(i, idx)) {
                isPlaced[i] = true;
                board[i][idx] = 'Q';
                backTrace(n, idx + 1);
                isPlaced[i] = false;
                board[i][idx] = '.';
            }
        }
        return;
    }
};

int main() {
    Solution s;
    for(int n=1;n<=9;n++){
        cout<<s.totalNQueens(n)<<endl;
    }
}