#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

// 空间 O(n)
class Solution {
public:
    int count;
    // 放置的行, 两条对角线，diag1 (i+j), diag2(i-j);
    unordered_set<int> rowPlaced,diag1,diag2;
    int totalNQueens(int n) {
        count = 0;
        backTrace(n, 0);
        return count;
    }
    //     int bias = 1;
    //     for(int j = col-1;j>=0;j--){
    //         if(row-bias >=0 && board[row-bias][j] == true){
    //             return false;
    //         }
    //         if(row+bias < board.size() && board[row+bias][j] == true){
    //             return false;
    //         }
    //         bias++;
    //     }
    //     return true;
    // }

    void backTrace(int n, int col){
        if(n==col){
            count++;
            return;
        }
        for(int i=0;i<n;i++){
            if(!rowPlaced.count(i) && !diag1.count(i+col) && !diag2.count(i-col)){
                rowPlaced.insert(i);
                diag1.insert(i+col);
                diag2.insert(i-col);
                backTrace(n, col+1);
                rowPlaced.erase(i);
                diag1.erase(i+col);
                diag2.erase(i-col);
            }
        }
    }
};

class _Solution {
public:
    vector<vector<bool>> board;
    int count;
    vector<bool> hasRowPlaced;
    int totalNQueens(int n) {
        board = vector<vector<bool>> (n,vector<bool>(n,false));
        count = 0;
        hasRowPlaced = vector<bool>(n,false);
        backTrace(n, 0);
        return count;
    }

    bool canPlace(int row, int col){
        int bias = 1;
        for(int j = col-1;j>=0;j--){
            if(row-bias >=0 && board[row-bias][j] == true){
                return false;
            }
            if(row+bias < board.size() && board[row+bias][j] == true){
                return false;
            }
            bias++;
        }
        return true;
    }

    void backTrace(int n, int col){
        if(n==col){
            count++;
            return;
        }
        for(int i=0;i<n;i++){
            if(!hasRowPlaced[i] && canPlace(i, col)){
                hasRowPlaced[i] = true;
                board[i][col] = true;
                backTrace(n, col+1);
                board[i][col] = false;
                hasRowPlaced[i] = false;
            }
        }
    }
};
int main() {
    Solution s;
    for(int n=1;n<=9;n++){
        cout<<s.totalNQueens(n)<<endl;
    }
}