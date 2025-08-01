#include <queue>
#include <vector>
using namespace std;

class Solution {
  public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size();
        vector<int> board_1d(n * n + 1); // 编号从1开始，0忽略
        vector<int> visited(n * n + 1, 0);
        // flatten 为一维
        bool isRight = true;
        for (int i = n - 1, id = 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (isRight) {
                    board_1d[id] = board[i][j];
                } else {
                    board_1d[id] = board[i][n - 1 - j];
                }
                id++;
            }
            isRight = !isRight;
        }
        queue<pair<int, int>> queue1; // 代表目的元素的id和step;
        queue1.push({1, 0});
        while (!queue1.empty()) {
            auto elem = queue1.front();
            queue1.pop();
            int id = elem.first;
            // 第一次访问到的一定是步数最小的
            for (int i = 0; i < 6; i++) { // 至多走六步
                int next = id + i + 1;
                if (next > n * n)
                    break;
                // 可以跳转
                if (board_1d[next] != -1) {//检查目标地址是否有梯子或蛇 而不是id
                    next = board_1d[next];
                } 
                // 第一个到达终点
                if(next == n*n){
                    return elem.second+1;
                }
                if(visited[next]==0){//未访问过
                    visited[next]=1;
                    queue1.push({next,elem.second+1});
                }

            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<vector<int>> b = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    s.snakesAndLadders(b);
}