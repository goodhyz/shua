
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include<unordered_map>
using namespace std;


class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            vector<vector<string>> res;
            if(strs.size()==0)return res;
            vector<string> strs_copy = strs;
            for(string &str:strs){
                sort(str.begin(),str.end());
            }
            unordered_map<string,vector<int>> myMap; //可以直接用排序后的字符串做key，原字符串做value
            for(int i=0;i<strs.size();i++){
                myMap[strs[i]].push_back(i);
            }
            vector<string> tmp;
            for(auto pairs:myMap){
                tmp.clear();
                for(auto ss:pairs.second){
                    tmp.push_back(strs_copy[ss]);
                }
                res.push_back(tmp);
            }
            return res;
        }
    };