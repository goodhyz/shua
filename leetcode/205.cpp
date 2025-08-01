
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> myMap1,myMap2;
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i], c2 = t[i];
            auto it1 = myMap1.find(c1); // 指针 for 返回的是pair键值对 
            if (it1 != myMap1.end()) {
                if (it1->second != c2) {
                    return false;
                }
            } else {
                myMap1.insert({c1, c2}); // 注意insert要加{}
            }

            auto it2 = myMap2.find(c2); // 指针
            if (it2 != myMap2.end()) {
                if (it2->second != c1) {
                    return false;
                }
            } else {
                myMap2.insert({c2, c1}); // 注意insert要加{}
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    string s1 = "egg";
    string t1 = "add";
    cout << s.isIsomorphic(s1, t1);
}