#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    // 朴素做法
    vector<int> findSubstring2(string s, vector<string> &words) {
        int vec_size = words.size(), word_size = words[0].length(), substr_len = vec_size * word_size;
        vector<int> res;
        if (s.length() < substr_len)
            return res;
        string word;
        unordered_map<string, int> myMap, copyMap;
        for (auto word : words) {
            auto it = myMap.find(word);
            if (it != myMap.end()) { // 查找到
                myMap[word]--;
            } else {
                myMap[word] = -1;
            }
        }
        copyMap = myMap;

        for (int right = 0; right < s.length() - substr_len + 1; right++) {
            string sub_str = s.substr(right, substr_len);
            myMap = copyMap;
            // 根据子串更新map
            for (int i = 0; i < substr_len / word_size; i++) {
                word = sub_str.substr(i * word_size, word_size);
                auto it = myMap.find(word);
                if (it != myMap.end()) { // 查找到
                    myMap[word]++;
                } else {
                    myMap[word] = 1;
                }
            }
            // 判断是否为子串
            bool flag = true;
            for (const auto &pair : myMap) {
                if (pair.second != 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) { // 是子串
                res.push_back(right);
            }
        }
        return res;
    }

    // 滑动窗口
    vector<int> findSubstring(string s, vector<string> &words) {
        string word;
        vector<int> res;
        unordered_map<string, int> myMap;
        int vec_size = words.size(), word_size = words[0].length(), substr_len = vec_size * word_size;
        for (int i = 0; i < word_size; i++) {
            word = "";
            int word_count = 0;
            for (auto word : words) {
                auto it = myMap.find(word);
                if (it != myMap.end()) { // 查找到
                    myMap[word]--;
                } else {
                    myMap[word] = -1;
                }
            }
            for (int right = i; right < s.length(); right++) {
                word += s[right];
                if ((right + 1-i) % word_size == 0) {
                    auto it = myMap.find(word);
                    if (it != myMap.end()) { // 查找到
                        myMap[word]++;
                    } else {
                        myMap[word] = 1;
                    }
                    word_count++;
                    bool flag = true;
                    if (word_count == vec_size) { // 判断是否为serial subString
                        for (const auto &pair : myMap) {
                            if (pair.second != 0) {
                                flag = false;
                                break;
                            }
                        }
                        if (flag) { // 是子串
                            res.push_back(right - vec_size * word_size + 1);
                        }
                        // 减去开头
                        word = s.substr(right - substr_len + 1, word_size);
                        myMap[word]--;
                        if (myMap[word] == 0)
                            myMap.erase(word);
                        word_count--;
                    }
                    word = "";
                }
            }
            myMap.clear();
        }
        return res;
    }
};

int main() {
    string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> words = {"fooo","barr","wing","ding","wing"};
    Solution solution;
    auto it = solution.findSubstring(s, words);
    for (auto elem : it) {
        cout << elem;
    }
}