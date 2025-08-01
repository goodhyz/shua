#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    int trailingZeroes(int n) {
        int zeroCount=0;
        while(n){
            zeroCount+=n/5;
            n/=5;
        }
        return zeroCount;
    }
};