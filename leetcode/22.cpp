#include <string>
#include <vector>
#include<iostream>
using namespace std;

class Solution {
  private:
    vector<string> res;
    string path;
    vector<char> list;

  public:
    vector<string> generateParenthesis(int n) {
        // left = right =0;
        list.push_back('(');
        list.push_back(')');
        backtrace(n, 0,0);
        return res;
    }
    void backtrace(int n, int left, int right) {
        if(left<right)return;
        if (path.size() == 2 * n ) {
            if(left==right){
            res.push_back(path);}
            return;
        }
        for (auto c : list) {
            path.push_back(c);
            if (c == '(') {
                backtrace(n, left + 1, right);
            } else {
                backtrace(n, left, right+1);
            }
            path.pop_back();
        }
    }
};

int main(){
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    for(const auto & str:res){
        cout<<str<<endl;
    }

}