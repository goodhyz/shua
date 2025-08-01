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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> res;
            if(nullptr==root)return res;
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                int size=q.size();
                vector<int>layer;
                for(int i=0;i<size;i++){
                    TreeNode*tmp = q.front();
                    q.pop();
                    layer.push_back(tmp->val);
                    if(tmp->left)q.push(tmp->left);
                    if(tmp->right)q.push(tmp->right);
                }
                res.push_back(layer);
            }
            return res;
        }
    };