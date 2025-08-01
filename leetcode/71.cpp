#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
  public:
    string simplifyPath(string path) {
        vector<string> stack1;
        string str;
        if(path.back()!='/')path+='/';
        for (auto c : path) {
            if (c == '/' && !str.empty()) {//遇到/ 并且str不为空
                if (str == "..") {
                    if (!stack1.empty())
                        stack1.pop_back();
                    str.clear();
                    continue;
                }
                if (str == ".") {
                    str.clear();
                    continue;
                }
                stack1.push_back(str);
                str.clear();
                continue;
            }
            if (c != '/') {
                str += c;
            }
        }
        string ret = "";
        for (auto s:stack1) {
            ret += '/'+s;
        }
        return ret.empty()?"/":ret;
    }
};
class Solution {
    public:
        string simplifyPath(string path) {
            vector<string> stk;
            istringstream ss(path);
            string s;
            while(getline(ss,s,'/'))
            {
                if(s.empty()||s==".")
                {
                    continue;
                }
                if(s!="..")
                {
                    stk.push_back(s);
                }
                else if(!stk.empty())
                {
                    stk.pop_back();
                }
               
            }
            string ans;
                for(string &s :stk)
                {
                    ans+='/';
                    ans+=s;
                }
            return stk.empty()?"/":ans;
        }
    };
int main(){
    Solution s;
    string p = "/../";
    s.simplifyPath(p);
}