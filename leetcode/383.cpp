
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            if(ransomNote.length()>magazine.length())return false;
            int myMap[26]={0};
            for(auto &s:ransomNote){
                myMap[s-'a']++;
            }
            for(auto &s:magazine){
                myMap[s-'a']--;
            }
            for(auto &elem:myMap){
                if(elem>0)return false;
            }
            return true;
        }
    };