/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    vector<TreeNode *> path1,path2;
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        vector<TreeNode *>path;
        findPath(root,path,p,q);
        int min_len = min(path1.size(),path2.size());
        while(min_len--){
            if(path1[min_len]==path2[min_len])return path1[min_len];
        }
        return nullptr;
    }

    void findPath(TreeNode *root, vector<TreeNode *> &path, TreeNode *p, TreeNode *q) {
        if(nullptr==root){
            return;
        }
        path.push_back(root);
        if(p==root)path1 = path;
        if(q==root)path2=path;
        findPath(root->left,path,p, q);
        findPath(root->right,path,p,q);
        path.pop_back();
    }   
};