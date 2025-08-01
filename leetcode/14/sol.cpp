#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int min_len = 200;
            for(auto str : strs){
                min_len = min(min_len, (int)str.size());
            }
            // 复杂度O()
            for(int i=0; i<min_len; i++){
                for(int j=1; j<strs.size(); j++){
                    if(strs[j][i] != strs[j-1][i]){
                        return strs[j].substr(0, i);
                    }
                }
            }
            return strs[0].substr(0, min_len);
        }
    };

    int main(){
        Solution s;
        vector<string> strs = {"flower", "flow", "flight"};
        cout << s.longestCommonPrefix(strs) << endl;
        return 0;
    }