#include<string>
#include<stack>
#include<vector>
using namespace std;

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> stack1;
            for(string s :tokens){
                if(s=="+"||s=="-"||s=="*"||s=="/"){
                    int v2 = stack1.top();
                    stack1.pop();
                    int v1 = stack1.top();
                    stack1.pop();
                    if(s=="+")stack1.push(v1+v2);
                    if(s=="-")stack1.push(v1-v2);
                    if(s=="*")stack1.push(v1*v2);
                    if(s=="/")stack1.push(v1/v2);
                }else{
                    int val = stoi(s);
                    stack1.push(val);
                }

            }
            return stack1.top();
        }
    };