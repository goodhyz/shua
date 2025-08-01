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
        int maxPath;
    public:
        int maxPathSum(TreeNode* root) {
            maxPath=INT_MIN;
            dfs(root);
            return maxPath;
        }

        // 重点 当子树小于0时丢弃
        int dfs(TreeNode* root){
            if(nullptr==root){
                return 0;
            }
            int left  = max(dfs(root->left),0);
            int right= max(dfs(root->right),0);
            maxPath = max(left+right+root->val,maxPath);
            return max(left,right)+root->val;
        }
    };
int main(){
    
}