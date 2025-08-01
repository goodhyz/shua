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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (nullptr == root)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {
            int size = q.size();
            vector<int> layer;
            depth++;
            for (int i = 0; i < size; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                if(depth%2){//顺
                    layer.push_back(tmp->val);
                }else{
                    layer.insert(layer.begin(), tmp->val);
                }
                if (tmp->left){
                    q.push(tmp->left);}
                if (tmp->right){
                    q.push(tmp->right);}
                // if(tmp->right)q.push(tmp->right);
            }
            res.push_back(layer);
        }
        return res;
    }
};