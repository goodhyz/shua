#include <algorithm>
#include <iostream>
#include <vector>
#include<map>
#include <string>
using namespace std;

class Solution {
    private:
    map <char, int> roman{
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    public:
        int romanToInt(string s) {

            int result = 0;
            for(int i = 0; i < s.size(); i++){
                if(i < s.size() - 1 && roman[s[i]] < roman[s[i + 1]]){
                    result -= roman[s[i]]; //直接减去当前值
                }else{
                    result += roman[s[i]];
                }
            }
            return result;
        }
    };