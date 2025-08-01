
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 易错点 当s的单词数量和pattern的长度不同时，需要单独判断
// 用输入输出可以分割字符串，方便的一
class Solution {
  public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> myMap1;
        unordered_map<string, char> myMap2;
        int last_pos=0;
        string str;
        for (int i = 0; i < pattern.length(); i++) {
            str ="";
            if(last_pos==s.length()+1)return false; // pattern 还没遍历完，但是s已经没有单词了
            while(s[last_pos]!=' '&&last_pos<s.length()){
                str+=s[last_pos];
                last_pos++; 
            }
            last_pos++;
            char c = pattern[i];

            /*简便写法
            if (str2ch.count(tmp) && str2ch[tmp] != ch) {
                return false;
            }
            if (ch2str.count(ch) && ch2str[ch] != tmp) {
                return false;
            }
             */

            auto it1 = myMap1.find(c); // 指针 for 返回的是pair键值对
            if (it1 != myMap1.end()) {
                if (it1->second != str) {
                    return false;
                }
            } else {
                myMap1.insert({c, str}); // 注意insert要加{}
            }

            auto it2 = myMap2.find(str); // 指针
            if (it2 != myMap2.end()) {
                if (it2->second != c) {
                    return false;
                }
            } else {
                myMap2.insert({str, c}); // 注意insert要加{}
            }
        }
        if(last_pos!=s.length()+1)return false;
        return true;
    }
};

int main() {
    Solution s;
    string s1 = "abba";
    string t1 = "dog cat cat";
    cout << s.wordPattern(s1, t1);
}