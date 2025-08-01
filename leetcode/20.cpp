#include <iostream>
#include <stack>

using namespace std;

class Solution {
  public:
    bool isValid(string s) {
        if(s.empty())return true;
        stack<char> stack1;
        stack1.push(s[0]);
        for (int i=1;i<s.length();i++) {
            char c = s[i];
            if(stack1.empty()){
                stack1.push(c);
                continue;
            }
            char last_c = stack1.top();
            if (last_c == '[' && c == ']' ||last_c == '(' && c == ')'||last_c == '{' && c == '}') {
                stack1.pop();
            }else{
                stack1.push(c);
            }
        }
        return stack1.empty();
    }
};