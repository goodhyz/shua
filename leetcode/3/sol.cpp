#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            if(s.length()==1 || s.length()==0)return s.length();
            
            int l1=0,len=1;
            int max_len = 1;
            deque<char> subString;
            subString.push_back(s[l1]);
            for(int l2=1;l2<s.length();l2++){
                char tmp = s[l2];
                auto it = std::find(subString.begin(),subString.end(),tmp);
                if(it!=subString.end()){
                    // 计算找到重复字符时的长度
                    int idx = it - subString.begin(); //在子串的位置
                    len -= idx; 
                    subString.push_back(s[l2]);
                    while(idx-->=0){
                        subString.pop_front();
                    }
                }else{
                    len++;
                    subString.push_back(s[l2]);
                    max_len = max (max_len,len);
                }
            }
            return max_len;
        }

    };

    int main(){
        Solution s;
        string myStr = "aabaab!bb";
        string myStr1 ="abcabcbb";
        cout<<s.lengthOfLongestSubstring(myStr);
    }