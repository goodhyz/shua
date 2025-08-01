#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            int rows[9][9]={0};
            int cols[9][9]={0};
            int regions[3][3][9]={0};
            for(int i =0;i<9;i++){
                for(int j =0 ;j<9 ;j++){
                    char tmp = board [i][j];
                    if(tmp == '.')continue;
                    rows[i][tmp-'1']++;
                    cols[j][tmp-'1']++;
                    regions[i/3][j/3][tmp-'1']++;
                    if(rows[i][tmp-'1']>1||cols[j][tmp-'1']>1||regions[i/3][j/3][tmp-'1']>1)return false;
                }
            }
            return true;
        }
    };
