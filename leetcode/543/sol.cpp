/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>

using namespace std;
class TreeNode {
  public:
    TreeNode(int v, TreeNode *l = nullptr, TreeNode *r = nullptr) {
        val = v;
        left = l;
        right = r;
    }
    TreeNode *left;
    TreeNode *right;
    int val;
};
class Solution {
  private:
    int maxDiameter;

  public:
    int diameterOfBinaryTree(TreeNode *root) {
        maxDiameter = 0;
        dfs(root);
        return maxDiameter;
    }

    int dfs(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        maxDiameter = max(maxDiameter, left + right);
        return max(left, right) + 1;
    }
};
