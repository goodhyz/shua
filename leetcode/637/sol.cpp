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
        vector<double> averageOfLevels(TreeNode* root) {
            vector<double>average;
            if(nullptr==root)return average;
            queue<TreeNode*>q;
            q.push(root);
            while(!q.empty()){
                double sum=0;
                TreeNode* tmp;
                int size = q.size();
                for(int i=0;i<size;i++){
                    tmp = q.front();
                    q.pop();
                    sum+=tmp->val;
                    if(tmp->left)q.push(tmp->left);
                    if(tmp->right)q.push(tmp->right);
                }
                sum/=size;
                average.push_back(sum);
            }
            return average;
        }
    };