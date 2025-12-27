#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    map<int, vector<int>> countIdx;
    int count = 1;int max_count=0;
    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1]) {
            countIdx[count].push_back(i-1);
            max_count = max(max_count,count);
            count=1;
        }else{
            count++;
        }
    }
    countIdx[count].push_back(n-1);
    max_count = max(max_count,count);
    for(auto idx:countIdx[max_count]){
        if(idx-max_count-1>=0&&nums[idx-max_count-1]==nums[idx]){
            cout<<max_count+1;
            return 0;
        }
        if(idx+2<n&&nums[idx+2]==nums[idx]){
            cout<<max_count+1;
            return 0;
        }
    }
    cout<<max_count;

}