#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> res;
            vector<string> line_word;
            string line = "";
            int count = 0,len=0;
            for(int i=0;i<words.size();i++){
                if(words[i].length()+len+count<=maxWidth){
                    count++;
                    len += words[i].size();
                    line_word.push_back(words[i]);
                    if(i == words.size()-1){
                        line = align_left(line_word, maxWidth);
                        res.push_back(line);
                        cout<<line<<endl;
                    }
                }else{
                    if(count==1){
                        line = align_left(line_word, maxWidth);
                        res.push_back(line);
                        cout<<line<<endl;
                        line_word.clear();line = "";count = 0;len = 0;
                        i --;
                        continue;
                    }
                    line = align_center(line_word, maxWidth);
                    cout<<line<<endl;
                    res.push_back(line);
                    line_word.clear();line = "";count = 0;len = 0;
                    i--;
                }
            }
            return res;
        }
        string align_left (vector<string>& line_word, int maxWidth){
            string line = "";
            for(int i=0;i<line_word.size();i++){
                line += line_word[i];
                if(i != line_word.size()-1){
                    line += " ";
                }
            }
            while(line.size()<maxWidth){
                line += " ";
            }
            return line;
        }

        string align_center (vector<string>& line_word, int maxWidth){
            string line = "";
            int len = 0;
            for(int i=0;i<line_word.size();i++){
                len += line_word[i].size();
            }
            int space = (maxWidth - len)/(line_word.size()-1);
            int extra = (maxWidth - len)%(line_word.size()-1);
            for(int i=0;i<line_word.size();i++){
                line += line_word[i];
                if(i != line_word.size()-1){
                    for(int j=0;j<space;j++){
                        line += " ";
                    }
                    if(extra){
                        line += " ";
                        extra--;
                    }
                }
            }
            return line;
        }
    };

int main(){
    Solution s;
    vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    int maxWidth = 16;
    s.fullJustify(words, maxWidth);
}