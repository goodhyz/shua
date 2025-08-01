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

class Solution1 {
  private:
    unordered_map<int, int> inorder_map;

  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // 可以用哈希表优化
        // int root_idx ;
        // for(int i=0;i<inorder.size();i++){
        //     if(root_val == inorder[i]){
        //         root_idx = i;
        //         break;
        //     }
        // }
        // 根据val找到节点在inorder中的索引
        inorder_map.clear(); // 调用一次清除一次
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }
        return buildSubTree(inorder, postorder,0, postorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode *buildSubTree(vector<int> &inorder, vector<int> &postorder, int in1, int in2, int p1, int p2) {
        if(in1>in2||p1>p2)return NULL;
        int root_val=postorder[p2];
        TreeNode *root = new TreeNode(root_val);
        int root_idx = inorder_map[root_val];
        int left_size = root_idx - in1;
        root->left=buildSubTree(inorder,postorder,in1,in1+left_size-1,p1,p1+left_size-1);
        root->right =buildSubTree(inorder,postorder,in1+left_size+1,in2,p1+left_size,p2-1);
        return root;
    }
};
class Solution {
    private:
        unordered_map<int,int>inorder_map;
        int postorder_idx; 
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            postorder_idx = postorder.size()-1;
            for (int i = 0; i < inorder.size(); i++) {
                inorder_map[inorder[i]] = i;
            }
            return buildSubTree(postorder,0,postorder.size()-1);
        }
        //与前序遍历不同的是，这里要先构建右子树
        TreeNode* buildSubTree(vector<int>& postorder,int left,int right){
            if(left>right)return NULL;
            int root_val = postorder[postorder_idx--];
            TreeNode* root = new TreeNode(root_val);
            int root_idx = inorder_map[root_val];
            root->right = buildSubTree(postorder,root_idx+1,right);
            root->left=buildSubTree(postorder,left,root_idx-1);
            return root;
            
        }
    };

    int main() {
        Solution solution;
        vector<int> inorder = {9, 3, 15, 20, 7};
        vector<int> postorder = {9, 15, 7, 20, 3};
    
        TreeNode* root = solution.buildTree(inorder, postorder);

    
        return 0;
    }