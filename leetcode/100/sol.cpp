/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  /**
   * 深度优先搜索，用的是栈
   */
  bool _isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) {
      return true;
    }
    if (!p || !q) {
      return false;
    }

    return p->val == q->val && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
  }

  bool isSameTree(TreeNode *p, TreeNode *q) {
    queue<TreeNode *> left;
    queue<TreeNode *> right;
    left.push(p);
    right.push(q);
    while (!left.empty() || !right.empty()) {
      auto node1 = left.front();
      auto node2 = right.front();
      left.pop();
      right.pop();
      if (node1->val != node2->val)
        return false;
      if (!node1 && !node2)
        continue;
      if (!node1 || !node2)
        return false;
      auto left1 = node1->left, left2 = node1->right, right1 = node2->left,
           right2 = node2->right;
      left.push(left1);
      left.push(left2);
      right.push(right1);
      right.push(right2);
    }
    return true;
  }
};