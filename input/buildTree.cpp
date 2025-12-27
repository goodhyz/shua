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