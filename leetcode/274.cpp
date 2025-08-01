/*
h index  H指数
https://leetcode.cn/problems/h-index/description/?envType=study-plan-v2&envId=top-interview-150
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    public:
        // 条件判断怎么定？？
        int hIndex(vector<int>& citations) {
            sort(citations.begin(),citations.end(),greater<int>());
            int i=0,h=0;
            while(i<citations.size()&&citations[i]>h){
                i++;
                h++;
            }
            return h;
        }

        int hIndex1(vector<int>& citations) {
            sort(citations.begin(),citations.end(),greater<int>());
            int h;
            for(h=0;h<citations.size();h++){
                if(citations[h]<=h){
                    break;
                }
            }
            return h;
        }

        int hIndex2(vector<int>& citations) {
            int n = citations.size();
            vector<int> papers(n + 1, 0);
            for (int c: citations) {
                papers[min(c, n)]++;
            }
            int cite = n;
            for (int nums = papers[n]; cite > nums; nums += papers[cite]) {
                cite--;
            }
            return cite;
        }
    };

int main() {
    Solution solution;
    vector<int> citations = {3,1,1};
    int result = solution.hIndex2(citations);
    cout<<result<<endl;
    return 0;
}