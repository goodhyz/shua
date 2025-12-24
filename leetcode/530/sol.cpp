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
    int pre = -100000;
    int min_diff = 100000;
    int getMinimumDifference(TreeNode *root) {
        dfs(root);
        return min_diff;
    }

    // 二叉搜索树的中序遍历是有序的
    void dfs(TreeNode *root){
        if(!root)return;
        dfs(root->left);
        int diff = root->val - pre;
        pre = root->val;
        this->min_diff = min(min_diff,diff);
        dfs(root->right);
    }
};