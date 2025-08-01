#include <iostream>
#include <stack>
#include <string>

using namespace std;

// 有点复杂
class Solution1 {
  public:
    int calculate_with_no_brace(string s) {
        int ans = 0;
        string tmp;
        // 从后往前，不需要判断第一个符号为-的问题
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == ' ')
                continue;
            if (s[i] == '+') {
                ans += stoi(tmp);
                tmp.clear();
            } else if (s[i] == '-') {
                ans -= stoi(tmp);
                tmp.clear();
            } else {
                tmp.insert(tmp.begin(), s[i]);
            }
        }
        if (!tmp.empty()) { // 最后检查 tmp 是否为空
            ans += stoi(tmp);
        }
        return ans;
    }

    int calculate(string s) {
        string s_with_no_brack;
        stack<char> stack_brace;
        for (int i = 0; i < s.size(); i++) {
            // 正在处理括号
            while (!stack_brace.empty()) {
                if (s[i] == ')') {
                    string tmp;
                    // 计算
                    while (stack_brace.top() != '(') {
                        char top = stack_brace.top();
                        stack_brace.pop();
                        tmp.insert(tmp.begin(), top);
                    }
                    // 处理配对的'('
                    stack_brace.pop();
                    string res = to_string(calculate_with_no_brace(tmp));

                    /* 易错，结果为负数则会出现两个符号 检查第一个符号*/
                    if (stack_brace.empty()) { // 结束
                        if (res[0] == '-' && !s_with_no_brack.empty()) { //确保非空
                            if (s_with_no_brack.back() == '-') {
                                s_with_no_brack.back() = '+';
                            } else if (s_with_no_brack.back() == '+') {
                                s_with_no_brack.pop_back();
                                s_with_no_brack.push_back('-');
                            }
                            for (int i = 1; i < res.size(); i++) {
                                s_with_no_brack.push_back(res[i]);
                            }
                        } else {
                            for (auto c : res) {
                                s_with_no_brack.push_back(c);
                            }
                        }
                    } else {
                        // stack_brace 不为空
                        if (res[0] == '-') {
                            if (stack_brace.top() == '-') {
                                stack_brace.pop();
                                stack_brace.push('+');
                            } else if (stack_brace.top() == '+') {
                                stack_brace.pop();
                                stack_brace.push('-');
                            }
                            for (int i = 1; i < res.size(); i++) {
                                stack_brace.push(res[i]);
                            }
                        } else {
                            for (auto c : res) {
                                stack_brace.push(c);
                            }
                        }
                    }
                } else if (s[i] != ' ') {
                    stack_brace.push(s[i]);
                }
                i++;
            }
            if (s[i] == '(') {
                stack_brace.push(s[i]);
            } else {
                s_with_no_brack.push_back(s[i]);
            }
            // stack_num.push(c);
        }

        return calculate_with_no_brace(s_with_no_brack);
    }
};

class Solution{
    public:
    int calculate(string s){

    }
};

int main() {
    string s = "1-(2+3-(4+(5-(1-(2+4-(5+6))))))";
    Solution sol;
    cout << sol.calculate(s) << endl;
}