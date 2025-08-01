#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
  public:
    int get_diff(string a, string b) {
        int count = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                count++;
        }
        return count;
    }
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        // unordered_set<string> visited; //标记visited?
        unordered_set<string> s;
        for (auto word : wordList) {
            s.insert(word);
        }
        // 不存在endWord
        if (s.count(endWord) == 0)
            return 0; 
        // 有第一个
        if (s.count(beginWord))
            s.erase(beginWord);
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while (!q.empty() && !s.empty()) {
            auto elem = q.front();
            q.pop();
            for(auto it = s.begin();it!=s.end();){
                if(get_diff(elem.first,*it)==1){
                    if(*it == endWord){
                        return elem.second+1;
                    }
                    q.push({*it,elem.second+1});
                    it = s.erase(it); //erase 方法会返回一个指向被删除元素之后的迭代器
                }else{
                    ++it;
                }
            }
        }
        return 0;
    }
    int ladderLength2(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordListSets;
        unordered_set<string> visit;
    
        for (auto& word : wordList) {
            wordListSets.insert(word);
        }
    
        if (wordListSets.count(endWord) == 0) return 0;
    
        queue<string> q;
        q.push(beginWord);
        int step = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string word = q.front();
                q.pop();
                for (int j = 0; j < word.size(); j++) {
                    for (int k = 0; k < 26; k++) {
                        string tmp = word;
                        if (tmp[j] == 'a' + k) continue;
                        tmp[j] = 'a' + k;
    
                        if (tmp == endWord) return ++step;
                        if (wordListSets.count(tmp) != 0 && visit.count(tmp) == 0) {
                            visit.insert(tmp);
                            q.push(tmp);
                        }
                    }
                }
            }
            step++;
        }
        return 0;
    }
};

int main() {
    Solution solution;
    vector<string> wordList = {"hot", "dot", "tog", "cog"};
    string beginWord = "hit";
    string endWord = "cog";
    int result = solution.ladderLength(beginWord, endWord, wordList);
    cout << "The length of the shortest transformation sequence is: " << result << endl;
    return 0;
}