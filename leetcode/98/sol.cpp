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

#include <climits>
#include <iostream>
#include <stack>
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
// class Solution {
//     public:
//         bool isValidBST(TreeNode* root) {
//             if(nullptr==root)return false;
//             stack<TreeNode*> s;
//             TreeNode* cur = root;
//             long long  pre = LLONG_MIN;
//             while(!s.empty()||cur!=nullptr){
//                 while(cur){
//                     s.push(cur);
//                     cur=cur->left;
//                 }
//                 cur = s.top();
//                 s.pop();
//                 if (cur->val <= pre) return false;
//                 pre = cur->val;
//                 cur = cur->right;

//             }
//             return true;
//         }
//     };

// class Solution {
//   private:
//     TreeNode *pre = nullptr;

//   public:
//     bool isValidBST(TreeNode *root) {
//         if (root == nullptr)
//             return true;
//         if (!isValidBST(root->left))
//             return false;
//         if (pre && pre->val >= root->val)
//             return false;
//         pre = root;
//         if (!isValidBST(root->right))
//             return false;
//         return true;
//     }
// };

class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            return helper(root,LLONG_MIN,LLONG_MAX);
        }
        bool helper(TreeNode* root,long long lower,long long upper){
            if(root==nullptr)return true;
            if(root->val<=lower||root->val>=upper){
                return false;
            }
            return helper(root->left,lower,root->val)&&helper(root->right,root->val,upper);
        }
    };