#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque> //双端队列
using namespace std;

class Solution {
    public:
        string reverseWords(string s) {
            reverse(s.begin(), s.end()); //整个字符串翻转
            for(int pos = 0; pos < s.size(); pos++){
                if(s[pos] != ' '){
                    int start = pos;
                    while(pos < s.size() && s[pos] != ' '){
                        pos++;
                    }
                    reverse(s.begin() + start, s.begin() + pos);
                }
            }
            string res;
            int count = 0;
            for(int i = 0; i < s.size(); i++){
                if(s[i] != ' '){
                    if(count != 0){
                        res += ' ';
                    }
                    while(i < s.size() && s[i] != ' '){
                        res += s[i];
                        i++;
                    }
                    count++;
                }
            }
            return res;
        }
        string reverseWords1(string s) {
            int left = 0, right = s.size() - 1;
            // 去掉字符串开头的空白字符
            while (left <= right && s[left] == ' ') ++left;
    
            // 去掉字符串末尾的空白字符
            while (left <= right && s[right] == ' ') --right;
    
            deque<string> d;
            string word;
    
            while (left <= right) {
                char c = s[left];
                if (word.size() && c == ' ') {
                    // 将单词 push 到队列的头部
                    d.push_front(move(word));
                    word = "";
                }
                else if (c != ' ') {
                    word += c;
                }
                ++left;
            }
            d.push_front(move(word));
            
            string ans;
            while (!d.empty()) {
                ans += d.front();
                d.pop_front();
                if (!d.empty()) ans += ' ';
            }
            return ans;
        }
    
    作者：力扣官方题解
    链接：https://leetcode.cn/problems/reverse-words-in-a-string/solutions/194450/fan-zhuan-zi-fu-chuan-li-de-dan-ci-by-leetcode-sol/
    来源：力扣（LeetCode）
    著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    };

int main(){
    Solution s;
    string str = "  the sky is blue  ";
    cout << s.reverseWords(str) << endl;
    return 0;
}