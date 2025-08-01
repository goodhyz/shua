#include<bits/stdc++.h>

using namespace std;
class solution{
    

};
int main(){
    int N;
    cin>>N;
    // 构造图
    map<string,vector<string>> graph;
    string line;
    while(N--){
        getline(cin,line);
        stringstream ss(line);
        string pre,cur;
        ss>>pre;
        while(ss>>cur){
            graph[pre].push_back(cur);
            pre = cur;
        }
    }
    string start,end;
    cin>>start>>end;
}