/**
 * 二叉树搜索迭代器，实现中序遍历
 *
 * 尝试显式的用栈来实现中序遍历
 *
 */
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
  private:
    vector<int> inorder;
    int curr;

  public:
    BSTIterator(TreeNode *root) {
        curr = -1;
        inorderView(root);
    }

    int next() {
        curr++;
        return inorder[curr];
    }

    bool hasNext() {
        if (curr + 2 > inorder.size())
            return false;
        else
            return true;
    }

    void inorderView(TreeNode *root) {
        if (root == nullptr)
            return;
        inorderView(root->left);
        inorder.push_back(root->val);
        inorderView(root->right);
    }
};

// 显示使用栈实现中序遍历
void InorderTraversal(TreeNode *root) {
    stack<TreeNode *> s;
    TreeNode *cur = root;
    while (nullptr != cur || !s.empty()) {
        while (cur) {
            s.push(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        // 访问cur
        cur = cur->right;
    }
}

// 显示使用栈实现前序遍历
void PreoderTraversal(TreeNode *root) {
    if(nullptr==root)return;
    stack<TreeNode *> s;
    TreeNode *cur = root;
    s.push(root);
    while (!s.empty()) {
        cur = s.top();
        s.pop();

        // 访问cur 
        if(cur->right)s.push(cur->right);
        if(cur->left)s.push(cur->left);
    }
}

// 显示使用栈实现前序遍历
void PostorderTraversal(TreeNode*root){
    
}