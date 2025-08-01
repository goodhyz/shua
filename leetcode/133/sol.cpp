/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
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
/*
class Solution {
  public:
    Node *cloneGraph(Node *node) {
        if (nullptr == node)
            return node;
        unordered_map<Node *, Node *> visited;
        // visited.insert({node,new Node(node->val)});
        visited[node]=new Node(node->val);
        queue<Node*> queue1;
        queue1.push(node);
        while(!queue1.empty()){
            Node* cur = queue1.front();
            queue1.pop();
            for(auto new_node :cur->neighbors){
                if(!visited.count(new_node)){
                    queue1.push(new_node);
                    visited[new_node] = new Node(new_node->val);
                    // visited[cur]->neighbors.push_back(new Node(new_node->val)); //构造邻居应该是访问cur->neighbors的所有元素都赋值
                }
                visited[cur]->neighbors.push_back(visited[new_node]);
            }
        }
        return visited[node];

    }
};*/

class Solution {
  public:
    unordered_map <Node*,Node*> visited;
    Node *cloneGraph(Node *node) {
        if(node==nullptr)return node;
        //已经访问
        if(visited.count(node))return visited[node];

        //第一次访问，创建节点并存储
        Node* new_node = new Node(node->val);
        visited[node]=new_node;
        
        // 更新节点
        for(auto &neighbor:node->neighbors){
            new_node->neighbors.push_back(cloneGraph(neighbor));
        }

        return new_node;
    }
};