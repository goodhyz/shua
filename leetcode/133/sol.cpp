#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
  int val;
  vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node *>();
  }
  Node(int _val, vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};
// 迭代写法
class Solution {
public:
  unordered_map<Node *, Node *> visited;
  Node *cloneGraph(Node *node) {
    if (!node)
      return node;
    visited[node] = new Node(node->val);
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        Node* cur = q.front();
        q.pop();
        for(Node* nb: cur->neighbors){
            if(visited.count(nb)==0){
                visited[nb] = new Node(nb->val);
                q.push(nb);
            }
            visited[cur]->neighbors.push_back(visited[nb]);
        }
    }
    return visited[node];
  }
};

// 递归写法，dfs
// class Solution {
//   public:
//     unordered_map <Node*,Node*> visited;
//     Node *cloneGraph(Node *node) {
//         if(node == nullptr) return node;
//         // 访问过
//         if(visited.count(node)){
//             return visited[node];
//         }
//         // 没访问过
//         Node* new_node = new Node(node->val);
//         visited[node] = new_node;
//         for(Node* nb: node->neighbors){
//             new_node->neighbors.push_back(cloneGraph(nb));
//         }

//         return new_node;
//     }
// };