#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
/**
    几种情况：
    1. 左右子树中存在pq
    2. p=root,q 在子树中
    3，q=root,p 在子树中
    遇到p，q返回对应节点，在root进行判断
*/
class Solution {
public:
  vector<TreeNode *> path_p;
  vector<TreeNode *> path_q;
  vector<TreeNode *> path;

  //   TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  //   {
  //     dfs(root, p, q);
  //     int size_p = path_p.size(), size_q = path_q.size();
  //     int min_size = min(size_p, size_q) - 1;
  //     while (min_size >= 0) {
  //       if (path_p[min_size] == path_q[min_size]) {
  //         return path_p[min_size];
  //       } else {
  //         min_size--;
  //       }
  //     }
  //     return nullptr;
  //   }
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) {
      return nullptr;
    }
    if(root->val == p->val || root->val == q->val){
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p,q);
    TreeNode* right = lowestCommonAncestor(root->right, p,q);
    if(!left){
        return right;
    }
    if(!right){
        return left;
    }
    return root;
  }

  void dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == nullptr || (path_p.size() != 0 && path_q.size() != 0))
      return;
    path.push_back(root);
    if (root->val == p->val)
      path_p = path;
    if (root->val == q->val)
      path_q = path;
    dfs(root->left, p, q);
    dfs(root->right, p, q);
    path.pop_back();
  }
};

int main() {
  // 1 2 2 null 3 null 3
  // 构建树
  string line, node;
  getline(cin, line);
  stringstream ss(line);
  vector<string> node_list;
  int v;
  queue<TreeNode *> node_queue;
  while (ss >> node) {
    node_list.push_back(node);
  }
  int n = node_list.size();
  if (n == 0 || node_list[0] == "null") {
    // 空树
    return 0;
  }
  TreeNode *root = new TreeNode(stoi(node_list[0]));
  node_queue.push(root);
  int index = 0;
  while (index < n && !node_queue.empty()) {
    TreeNode *cur_node = node_queue.front();
    node_queue.pop();

    index++;
    if (index < n && node_list[index] != "null") {
      TreeNode *new_node = new TreeNode(stoi(node_list[index]));
      cur_node->left = new_node;
      node_queue.push(new_node);
    }
    index++;
    if (index < n && node_list[index] != "null") {
      TreeNode *new_node = new TreeNode(stoi(node_list[index]));
      cur_node->right = new_node;
      node_queue.push(new_node);
    }
  }
}