#include <cstddef>
#include <ios>
#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
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
class Solution {
public:
  bool dfs(TreeNode *l, TreeNode *r) {
    if (l == nullptr && r == nullptr)
      return true;
    if (l == nullptr or r == nullptr)
      return false;
    if (l->val != r->val)
      return false;
    return dfs(l->left, r->right) && dfs(l->right, r->left);
  }
  // 往不同方向dfs
  bool isSymmetric(TreeNode *root) {
    TreeNode *left = root->left, *right = root->right;
    return dfs(left, right);
  }

  bool isSymmetric1(TreeNode *root) {
    queue<TreeNode *> left_queue, right_queue;
    left_queue.push(root),right_queue.push(root);
    while(!left_queue.empty() && !right_queue.empty()){
      TreeNode* l = left_queue.front();
      TreeNode* r = right_queue.front();
      left_queue.pop();
      right_queue.pop();
      if(!l&& !r) continue;
      if((!l || !r) || l->val != r->val)return false;
      left_queue.push(l->left),left_queue.push(l->right);
      right_queue.push(r->right),right_queue.push(r->left);
    }
    return true;
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

  Solution sol;
  cout << sol.isSymmetric1(root) << endl;
}