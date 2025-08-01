#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
    public:
        string convert(string s, int numRows) {
            string res;
            if (numRows == 1) return s;
            int t = 2 * numRows - 2;
            for(int row = 0; row < numRows; row++){
                for(int i = row; i < s.size(); i += t){
                    // cout << s[i];
                    res += s[i];
                    if(row > 0 && row < numRows - 1 && i + t - 2*row < s.size()){
                        // cout << s[i + 2 * numRows - 2- row];
                        res += s[i + t- 2*row ];
                    }
                }
            }
            return res;
        }
    };     

int main(){
    Solution s;
    string str = "PAYPALISHIRING";
    string out ="PAHNAPLSIIGYIR";
    cout << s.convert(str, 3)<< endl;
    return 0;
}