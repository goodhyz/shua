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
    private:
        int total;
    public:
        int sumNumbers(TreeNode* root) {
            total=0;
            pathSum(root,0);
            return total;
        }
        //可以改返回类型为int
        void pathSum(TreeNode* root,int sum){
            if(nullptr==root){
                return;
            }
            sum=sum*10+root->val;
            pathSum(root->left,sum);
            pathSum(root->right,sum);
            if(!root->left&&!root->right){
                total+=sum;
                return;
            }
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
