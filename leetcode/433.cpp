#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
// class Node {
//   public:
//     string gene;
//     vector<Node *> neighbors;
//     Node(string s){
//         gene = s;
//     }
// };
class Solution {
  public:
    int minMutation(string startGene, string endGene, vector<string> &bank) {
        unordered_set<string> visited;
        queue<pair<string,int>> q;//重点还是这个数据结构 ，记录步数
        q.push({startGene,0}); 
        while(!q.empty()){
            auto e=q.front();
            q.pop();
            visited.insert(e.first);
            if(visited.count(endGene))return e.second;
            for(const string & gene2:bank){
                if(visited.count(gene2))continue;
                if(diffCount(e.first,gene2)==1){
                    q.push({gene2,e.second+1});
                    // visited.insert(gene2);
                }
            }
        }
        return -1;
    }

    int diffCount(string str1, string str2) {
        int count = 0;
        for (int i = 0; i < 8; i++) {
            if (str1[i] != str2[i]) //计算不同字符数量
                count++;
        }
        return count;
    }
};
