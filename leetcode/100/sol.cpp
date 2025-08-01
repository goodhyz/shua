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
    /**
     * 深度优先搜索，用的是栈
     */
    // bool isSameTree(TreeNode *p, TreeNode *q) {
    //     if (NULL == p && NULL != q || q == NULL && p != q)
    //         return false;
    //     if (NULL == p && NULL == q)
    //         return true;
    //     // if(p->val)
    //     return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(q->right, p->right);
    // }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) {
            return true;
        } else if (p == NULL || q == NULL) {
            return false;
        }

        queue<TreeNode*> left;
        queue<TreeNode*> right;
        left.push(p);
        right.push(q);
        while (!left.empty() && !right.empty()) {
            auto node1 = left.front();
            auto node2 = right.front();
            left.pop();right.pop();
            auto left1 =node1->left,left2=node1->right,right1=node2->left,right2=node2->right;
            if(node1->val!=node2->val)return false;
            if((NULL == left1)!=(NULL==right1)){ // 或
                return false;
            }
            if((NULL == left2)!=(NULL==right2)){
                return false;
            }
            if(left1){
                left.push(left1);
            }
            if(left2){
                left.push(left2);
            }
            if(right1){
                right.push(right1);
            }
            if(right2){
                right.push(right2);
            }
        }
        return left.empty()&&right.empty();
    }
};