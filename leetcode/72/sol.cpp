#include <bits/stdc++.h>

using namespace std;
class Solution {
    private:
      vector<vector<bool>> visited;
    //   string path;
      string word;
      int m,n;
      vector<pair<int, int>> directions;
    public:
      bool exist(vector<vector<char>> &board, string word) {
          m = board.size();
            n = board[0].size();
          this->word = word;
          directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
          visited = vector<vector<bool>>(m, vector<bool>(n, false));
          for (int i = 0; i < m; i++) {
              for (int j = 0; j < n; j++) {
                if(backTrace(board,0,i,j)){
                    return true;
                }
              }
          }
          return false;
      }
      // idx 下一个字母的
      bool backTrace(vector<vector<char>> &board, int idx, int r, int c) {
        if(idx==word.size()-1){
            return true;
        }
        visited[r][c]=true;
        for(auto & direction:directions){
            int new_r=r+direction.first,new_c=c+direction.second;
            if(new_c>=0 && new_r>=0 && new_c<n && new_r<m){
                if(visited[new_r][new_c]==false && board[new_r][new_c]==word[idx+1]){
                    if(backTrace(board,idx+1,new_r,new_c)){
                        return true;
                    }
                }
            }
        }
        visited[r][c]=false;
        return false;
      }
  };
  class Solution {
    private:
        // To check the board of rowIdx and colIdx with word[wordIdx]
        bool exist(std::vector<std::vector<char> >& board, const string& word, int rowIdx,
                   int colIdx, int wordIdx){
            // Indices are out of boarder =, return false
            if(rowIdx < 0 || rowIdx >= board.size() || colIdx < 0 || colIdx >= board[0].size()){
                return false;
            }
            else if(board[rowIdx][colIdx] != word[wordIdx]){
                return false;
            }
            else if(wordIdx == word.length() - 1){
                return true;
            }
            
            char temp = board[rowIdx][colIdx];
            board[rowIdx][colIdx] = '*'; // '*' means this position is already visited - can't revisit any more
            bool _exist = exist(board, word, rowIdx, colIdx + 1, wordIdx + 1) ||
                          exist(board, word, rowIdx + 1, colIdx, wordIdx + 1) ||
                          exist(board, word, rowIdx, colIdx - 1, wordIdx + 1) ||
                          exist(board, word, rowIdx - 1, colIdx, wordIdx + 1);
            board[rowIdx][colIdx] = temp; // Recover the board
            return _exist;
        }
        
    public:
        bool exist(std::vector<std::vector<char> >& board, string word) {
            if(board.empty()){
                return false;
            }
            
            int row = board.size();
            int col = board[0].size();
            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    if(exist(board, word, i, j, 0)){  // Set each cell as the beginning to test in turn
                        return true;
                    }
                }
            }
            return false;
        }
    };
int main(){
    vector<vector<char>> board ={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    Solution s;
    cout<<s.exist(board,"ABCCED");
}