#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), [](auto &a, auto &b) { return a[0] < b[0]; }); //&& a[1] < b[1];
        int count = 1;
        vector<int> mix=points[0];
        for (const auto &p : points) {
            if(mix[1]<p[0]){ //不相交，多出一个区间 在这出错了你真是个sb
                count++;
                mix=p;
            }else{
                mix[0]=max(p[0],mix[0]);
                mix[1]=min(p[1],mix[1]);
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> points ={{10,16},{2,8},{1,6},{7,12}};

    int result = solution.findMinArrowShots(points);
    cout << "需要的最少箭数: " << result << endl;

    return 0;
}