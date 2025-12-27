#include <bits/stdc++.h>

using namespace std;
class solution {
  private:
    int target;
    int min_count;
  public:
    int minCases(vector<int>& cases,int cols){
        target = ~(-1<<cols);
        min_count = 1000;
        backTrace(cases,0,0,0);
        if(min_count!=1000){
            return min_count;
        }
        return -1;
    }

    void backTrace(vector<int>& cases,int start,int last_val,int count){
        if(last_val == target){
            min_count = min (min_count,count);
            return;
        }
        for(int i=start;i<cases.size();i++){
            int new_val = last_val|cases[i];
            backTrace(cases,i+1,new_val,count+1);
        }
    }
};
int main() {
    int m,n;
    cin>>m>>n;
    vector<int>cases(m);
    int target = ~(-1<<n);
    // cout<<target;
    for(int i=0;i<m;i++){
        int num = 0;
        for(int j=0;j<n;j++){
            int bit;
            cin>>bit;
            num = num | bit<<(n-j-1);
        }
        cases[i]=num;
    }
    solution s;
    cout<<"result is"<<endl;
    cout<<s.minCases(cases,n)<<endl;
    
}