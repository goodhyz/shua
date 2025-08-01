/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#include <iostream>
#include <queue>
using namespace std;

class Node {
  public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
  public:
    // 广度优先，一层一层的链接
    Node *connect1(Node *root) {
        if (NULL == root)
            return root;
        queue<Node *> queue1;
        queue1.push(root);
        while (!queue1.empty()) {
            int len = queue1.size() - 1;
            Node *front = queue1.front();
            queue1.pop();
            if (front->left) {
                queue1.push(front->left);
            }
            if (front->right) {
                queue1.push(front->right);
            }
            Node *back;
            while (len) {
                back = queue1.front();
                queue1.pop();
                len--;
                front->next = back;
                front = back;
                if (front->left) {
                    queue1.push(front->left);
                }
                if (front->right) {
                    queue1.push(front->right);
                }
            }
        }
        return root;
    }

    // 在遍历每一层时，将第二层连接起来
    Node *connect2(Node *root) {
        Node *curr = root;
        Node *dummy = new Node(0); // 要创建一个对象，仅仅声明指针会出现访问空指针报错
        while (curr) {
            // 切换层；
            dummy->next = curr->left; // 指向下一层的开始
            Node *pre = dummy;
            while (curr) {
                // 遍历层
                if (curr->left) {
                    pre->next = curr->left;
                    pre = pre->next;
                }
                if (curr->right) {
                    pre->next = curr->right;
                    pre = pre->next;
                }
                curr = curr->next;
            }
            curr = dummy->next;
        }
        return root;
    }

    Node *connect(Node *root) {
        dfs(root,0);
        return root;
    }

    void dfs(Node *root, int depth) {
        if (NULL == root)
            return;
        if (depth == pre.size()) {
            pre.push_back(root);
        } else {
            pre[depth]->next = root;
            pre[depth]=root;
        }
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }

  private:
    vector<Node *> pre;
};