class Solution {
    private:
      vector<vector<int>> graph;
      vector<int> inDegree;
    public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
          graph.resize(numCourses);
          inDegree.resize(numCourses, 0);
          queue<int> queue1;
          vector<int> res;
          // int count =numCourses;
          for (const auto &edge : prerequisites) { //使用const & 可以优化时间
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
          return numCourses?vector<int>{}:res;
      }
  };