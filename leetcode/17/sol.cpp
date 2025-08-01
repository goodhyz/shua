#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    // public:
    // 广度优先的思想
    // vector<string> letterCombinations(string digits) {
    //     vector<string>res;
    //     if(digits.size()==0) return res;
    //     vector<string> m={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    //     queue<string> q;
    //     int n =digits.size();
    //     for(char s:m[digits[0]-'2']){
    //         q.push(string(1, s));
    //     }
    //     n--;
    //     while(n){
    //         int size = q.size();
    //         string str = m[digits[digits.size()-n]-50];
    //         for(int i=0;i<size;i++){
    //             string it = q.front();
    //             q.pop();
    //             for(const auto & s:str){
    //                 q.push(it+s);
    //             }

    //         }
    //         n--;
    //     }
    //     while(!q.empty()){
    //         res.push_back(q.front());
    //         q.pop();
    //     }
    //     return res;
    // }

    // 递归
  private:
    vector<string> res;
    string tmp;
    unordered_map<char, string> m;

  public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return res;
        m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        dfs(digits,0);
        return res;
    }
    void dfs(string digits, int index) {
        if(index == digits.size()){
            res.push_back(tmp);
            return;
        }
        string str = m[digits[index]];
        for(const char s:str){
            tmp+=s;
            dfs(digits,index+1);
            tmp.pop_back();
        }
    }
};

int main() {
}