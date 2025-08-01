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
    TreeNode* pre;
  public:
    void flatten1(TreeNode *root) {
        if (nullptr == root) return;
        flatten1(root->right);
        flatten1(root->left);
        root->left = nullptr;
        root->right = pre;
        pre = root;
    }

    void flatten(TreeNode *root){
        if(nullptr == root)return;
        TreeNode*curr = root;
        while(curr){
            if(nullptr != curr->left){
                TreeNode* next = curr->right;//这个变量其实多余，直接赋值就行，但注意要在curr->right改变前赋值
                TreeNode *start=curr->left;
                TreeNode *left_last=curr->left;
                while(nullptr!=left_last->right){
                    left_last = left_last->right;
                }
                curr->left = nullptr;
                curr->right = start;
                left_last->right = next;
            }
            curr=curr->right;
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
