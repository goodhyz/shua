
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        int myMap[26]={0};
        for(auto &c:s){
            myMap[c-'a']++;
        }
        for(auto &c:t){
            myMap[c-'a']--;
        }
        for(auto &elem:myMap){
            if(elem!=0)return false;
        }
        return true;
    }

    // 巧妙做法，排序后，如果是易位词，一定相等
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
    };