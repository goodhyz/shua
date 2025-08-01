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
    private:
        vector<int>view;
    public:
        vector<int> rightSideView(TreeNode* root) {
            if(root==nullptr)return view;
            dfs(root,0);
            return view;
        }

        void dfs(TreeNode* root,int depth){
            if(root==nullptr)return;
            if(depth>=view.size())view.push_back(root->val);
            else view[depth]=root->val;
            dfs(root->left,depth+1);
            dfs(root->right,depth+1);
        }
    };