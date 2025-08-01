#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
  public:
    int lengthOfLastWord(string s) {
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {//找到第一个字符
                int j = i;
                while (j >= 0 && s[j] != ' ') { // 从i开始往前找到第一个空格或者第一个字符j=0
                    j--;
                }
                return i - j;
            }
        }
        return 0;
    }
};