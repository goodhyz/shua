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
    unordered_map<int, int> inorder_map;

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
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
        return buildSubTree(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
    }

    TreeNode *buildSubTree(vector<int> &preorder, vector<int> &inorder, int pre1, int pre2, int in1, int in2) {
        if (pre1 > pre2)
            return NULL;
        int root_val = preorder[pre1];
        TreeNode *root = new TreeNode(root_val);
        int root_idx = inorder_map[root_val];
        int left_size = root_idx - in1; // 写成了pre1
        root->left = buildSubTree(preorder, inorder, pre1 + 1, pre1 + left_size, in1, in1 + left_size - 1);
        root->right = buildSubTree(preorder, inorder, pre1 + left_size + 1, pre2, in1 + left_size + 1, in2); // 第5个参数忘记+1
        return root;
    }
};
class Solution2 {
  public:
    unordered_map<int, int> inorderMap; // 记录中序遍历中每个值的索引
    int preorderIndex = 0;

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // 构建哈希表，存储中序遍历值对应的索引，方便查找根节点位置
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        return buildSubTree(preorder, 0, inorder.size() - 1);
    }

  private:
    TreeNode *buildSubTree(vector<int> &preorder, int left, int right) {
        // 递归终止条件：左边界超过右边界
        if (left > right) {
            return nullptr;
        }

        // 取当前 preorderIndex 位置的值作为根节点，并递增索引
        int rootVal = preorder[preorderIndex++];
        TreeNode *root = new TreeNode(rootVal);

        // 通过哈希表查找根节点在 inorder 数组中的位置
        int inorderRootIndex = inorderMap[rootVal];

        // 递归构建左子树（在 inorder 的左半部分）
        root->left = buildSubTree(preorder, left, inorderRootIndex - 1);

        // 递归构建右子树（在 inorder 的右半部分）
        root->right = buildSubTree(preorder, inorderRootIndex + 1, right);

        return root;
    }
};

// 测试代码
void printInOrder(TreeNode *root) {
    if (!root)
        return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    Solution solution;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = solution.buildTree(preorder, inorder);

    cout << "构建的二叉树的中序遍历结果: ";
    printInOrder(root);
    cout << endl;

    return 0;
}

int main() {
}