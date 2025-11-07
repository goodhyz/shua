// 在一次会议中每个人进行投票，现在有所有人的投票记录，请找出获得超过半数选票的候选者编号
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;



int main() {
    vector<int> input;
    string line;
    while(getline(cin, line)){
        stringstream ss(line);
        int num;
        while(ss >> num){
            input.push_back(num);
        }
    }
    sort(input.begin(), input.end());
    int n = input.size();
    int mid = input[n/2];
    if(count(input.begin(), input.end(), mid) > n/2){
        cout<<mid<<endl;
    }else{
        cout<<"-1"<<endl;
    }

    return 0;
}