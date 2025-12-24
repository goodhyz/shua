#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    int total_tank = 0;
    int curr_tank = 0;
    int starting_station = 0;
    for (int i = 0; i < n; ++i) {
      total_tank += gas[i] - cost[i];
      curr_tank += gas[i] - cost[i];
      if (curr_tank < 0) {
        starting_station = i + 1;
        curr_tank = 0;
      }
    }
    return total_tank >= 0 ? starting_station : -1;
  }
};

class _Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    vector<int> diff(n,0);
    int total = 0;
    for(int i=0;i<n;i++){
        diff[i] = gas[i] - cost[i];
        total += diff[i];
    }
    if(total<0){
        return -1;
    }
    int startPos =0;
    int sum = 0;
    for(int i=0;i<n;i++){
        sum+=diff[i];
        if(sum<0){
            sum=0;
            startPos=i+1;
        }
    }
    return startPos;
  }
};