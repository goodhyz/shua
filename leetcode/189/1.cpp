// 标号 1-n 的n个人首尾相接，1到3报数，报到3的退出，求最后一个人的标号
#include <cstddef>
#include <vector>
#include <iostream> 
using namespace std;

class Node {
public:
  Node *pre;
  Node *next;
  int num;
  Node(int v,Node* p = nullptr, Node* n = nullptr) { 
    num = v; 
    pre = p;
    next = n;
}
  
};

// int main1() {
//     int n =3;
//     //Node* head = Node(1);

// }

 int main() {
  int n = 3;
  vector<int> list;
  for (int i = 1; i <= n; i++) {
    list.push_back(i);
  }
  int k=1;
  int p=0;
  while(n!=1){
    if(k==0){
        list.erase(list.begin()+p);
        n--;
    }
    p++;
    k++;
    k=k%3;
    p=p%list.size();
  }
  cout<<list[0];
  return 0;
}