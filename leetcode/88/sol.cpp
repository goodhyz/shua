#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int p1=m-1,p2=n-1,p=m+n-1;
    while(p1>=0 && p2>=0) {
        if(nums1[p1] >= nums2[p2]) {
            nums1[p] = nums1[p1];
            p1--;
        } else {
            nums1[p] = nums2[p2];
            p2--;
        }
        p--;
    }
    while(p1>=0){
        nums1[p] = nums1[p1];
        p1--;
        p--;
    }
    while(p2>=0){
        nums1[p] = nums2[p2];
        p2--;
        p--;
    }
  }
};
int main() { 
    /*
    3 3
    1 2 3 0 0 0 
    2 5 6
    */
    vector<int> nums1, nums2;
    int m,n;
    string line;
    cin >> m >> n;
    cin.ignore(); 
    getline(cin, line);
    stringstream ss(line);
    int num;
    while(ss >> num){
        nums1.push_back(num);
    }
    getline(cin, line);
    ss.clear();
    ss.str(line);
    while(ss >> num){
        nums2.push_back(num);
        nums1.push_back(0);
    }
    Solution s;
    s.merge(nums1,m,nums2,n);
    for(int i=0;i<m+n;i++){
        cout<<nums1[i]<<" ";
    }
    return 0; 

}