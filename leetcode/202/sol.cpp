#include <cmath>
#include <unordered_set>
// #include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int getSum(int n) {
    int sum = 0;
    while(n){
        sum+=pow(n%10, 2);
        n = n/10;
    }
    return sum;
  }
  bool isHappy(int n) {
    unordered_set<int> set;
    while(1){
        int sum = getSum(n);
        if(set.count(sum)>0){
            return false;
        }else if(sum == 1){
            return true;
        }
        set.insert(sum);
        n = sum;
    }
  }
};

int main() {
  Solution s;
  int n = 19;
  // cin >> n;
  cout << s.isHappy(n) << endl;
}