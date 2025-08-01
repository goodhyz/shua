#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            int left = 0,right=s.size()-1;
            if (left == right) return true;
            while(left<right){
                if(left < s.size() && !isAlpha(s[left])){
                    left++;
                    continue;
                }
                if(right >= 0 && !isAlpha(s[right])){
                    right--;
                    continue;
                }
                if(!isEquals(s[left],s[right])){
                    return false;
                }
                left++;
                right--;
            }
            return true;
        }

        bool isAlpha(char c){
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9')){
                return true;
            }
            return false;
        }
        bool isEquals(char c1,char c2){
            if(c1>='0' && c1<='9'){
                return c1 == c2;
            }
            // 易错点 数字 和 大写字母的ascii码相差32 会返回true
            if(c1 == c2 || abs(c1-c2) == 32){
                return true;
            }
            return false;
        }
    };

int main(){
    Solution s;
    string str = "0P";
    cout<<int('0')<<endl;
    cout<<int('P')<<endl;
    cout << s.isPalindrome(str) << endl;}