#include <string>
// #include
using namespace std;
class Node {
  public:
    Node *next;
    bool isEnd;
    Node() {
        next = nullptr;
        isEnd = false;
    }
};
class Trie {
  private:
    Node *root;

  public:
    Trie() {
        root = new Node[26];
    }

    void insert(string word) {
        Node *cur = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            int idx = c - 'a';
            if (cur[idx].next == nullptr) {
                cur[idx].next = new Node[26];
            }
            if (i + 1 == word.size()) {
                cur[idx].isEnd = true;
            } else
                cur = cur[idx].next;
        }
    }

    bool search(string word) {
        Node *cur = root;
        int idx;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            idx = c - 'a';
            if (cur[idx].next == nullptr)
                return false;
            if (i + 1 != word.size())
                cur = cur[idx].next;
        }
        return cur[idx].isEnd;
    }

    bool startsWith(string prefix) {
        Node *cur = root;
        for (auto c : prefix) {
            int idx = c - 'a';
            if (cur[idx].next == nullptr)
                return false;
            cur =cur[idx].next;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */