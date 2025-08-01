#include <queue>
#include <vector>
using namespace std;

// 使用dfs
/*
class Solution {
  private:
    vector<vector<int>> graph;
    vector<int> visited;
    bool flag = true;

  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        // 根据图的大小赋值
        graph.resize(numCourses);
        visited.resize(numCourses, 0); // 0:未访问 1:本次dfs访问 2:其他dfs访问过
        for (auto edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }
        for (int i = 0; i < numCourses && flag; i++) {
            if (visited[i] == 0)
                dfs(i);
        }
        return flag;
    }

    void dfs(int num) {
        visited[num] = 1;
        vector<int> neighbors = graph[num];
        for (int neighbor : neighbors) {
            if (!flag)
                break;
            if (visited[neighbor] == 1) { // 已经有环
                flag = false;
            } else if (visited[neighbor] == 0) { // 还没被访问过
                dfs(neighbor);
            }
            // 注意 不需要再访问2的节点，因为已经进行dfs了
        }
        visited[num] = 2;
    }
};
*/

// 使用bfs
class Solution {
    private:
      vector<vector<int>> graph;
      vector<int> inDegree;
    public:
      bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
          graph.resize(numCourses);
          inDegree.resize(numCourses, 0);
          queue<int> queue1;
          vector<int> res;
          // int count =numCourses;
          for (auto edge : prerequisites) {
              graph[edge[1]].push_back(edge[0]);
              inDegree[edge[0]]++;
          }
          for(int i=0;i<inDegree.size();i++){
              if(!inDegree[i])queue1.push(i);//入队的是索引，不是值，又犯低级错误
          }
          while(!queue1.empty()){
              int p = queue1.front();
              queue1.pop();
              res.push_back(p);
              vector<int> edges = graph[p];
              for(int edge:edges){
                  if(--inDegree[edge]==0)queue1.push(edge);
              }
              numCourses--;
          }
          return !numCourses;
      }
  };
int main() {
    Solution s;
    int num = 2;
    vector<vector<int>> pre = {{0, 1}};
    s.canFinish(num, pre);
}