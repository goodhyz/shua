#include <iostream>
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
        bool hasPathSum(TreeNode* root, int targetSum) {
            return getSum(root,0,targetSum);
        }
        bool getSum(TreeNode* root, int accumulatedVal,int targetSum){
            if(nullptr==root){
                return false;
            }
            accumulatedVal += root->val;
            if(!root->left&&!root->right)return accumulatedVal==targetSum;
            return getSum(root->left,accumulatedVal,targetSum)||getSum(root->right,accumulatedVal,targetSum);//重点在||
        }
    };

int main() {
    // Construct the binary tree:
    //       1
    //      / \
    //     2   5
    //    / \   \
    //   3   4   6
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

}
