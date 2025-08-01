#include <bits/stdc++.h>

using namespace std;

class Node {
  public:
    Node() {
        for (int i = 0; i < 26; i++) {
            p[i] = nullptr;
        }
        isEnd = false;
    }
    Node *p[26];
    bool isEnd;
};

class WordDictionary {
  private:
    Node *root;

  public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node *cur = root;
        for (auto alpha : word) {
            // null
            int idx = alpha - 'a';
            if (cur->p[idx] == nullptr) {
                cur->p[idx] = new Node();
            }
            cur = cur->p[idx];
        }
        cur->isEnd = true;
    }

    bool search(string word) {
        Node *cur = root;
        return searchHelp(cur, word, 0);
    }

    bool searchHelp(Node *cur, string &word, int idx) { // idx 查询字母的idx
        if (idx == word.size()) {
            return cur->isEnd;
        }
        if (cur == nullptr) {
            return false;
        }
        char alpha = word[idx];
        if (alpha == '.') {
            bool flag;
            for (int i = 0; i < 26; i++) {
                flag |= searchHelp(cur->p[i], word, idx + 1);
                if (flag)
                    return true;
            }
        } else {
            return searchHelp(cur->p[alpha - 'a'], word, idx + 1);
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main() {
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    wordDictionary.search("pad"); // 返回 False
    wordDictionary.search("bad"); // 返回 True
    wordDictionary.search(".ad"); // 返回 True
    wordDictionary.search("b.."); // 返回 True
}