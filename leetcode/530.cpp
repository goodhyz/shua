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

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
    int getMinimumDifference(TreeNode *root) {
        int pre = -100001;
        int minVal = INT_MAX;
        dfs(root,pre,minVal);
        return minVal;
    }

    // 二叉搜索树的中序遍历是有序的
    void dfs(TreeNode *root,int &pre, int &minVal){\
        if(root==nullptr)return ;
        dfs(root->left,pre,minVal);
        minVal = min(minVal,root->val-pre);
        pre=root->val;
        dfs(root->right,pre,minVal);
    }
};