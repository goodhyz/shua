// 给定s1,s2,给出不大于s2的s1最大值

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class solution {
  public:
   string maxStr (string&s1,string &s2){
    int l1=s1.size(),l2=s2.size();
    reverse(s1.begin(),s2.begin());
    int zero_count=0;
    while(s1[zero_count]==0){
        zero_count++;
    }
    // 特例剪枝
    if(l1-zero_count >l2||l1-zero_count == l2 && s1[zero_count]>s2[0]){
        return "-1";
    }
    // 
    string res;
    for(int i=0;i<l2;i++){

    }
   }
};