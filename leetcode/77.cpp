#include<vector>

using namespace std;

class Solution {
    private:
        vector<vector<int>> res;
        vector<int>tmp;
    public:
        vector<vector<int>> combine(int n, int k) {
            back(n,k,0,0);
            return res;
        }

        void back(int n, int k,int len,int start_idx){
            // 到点
            if(len==k){
                res.push_back(tmp);
                return;
            }
            // 横向
            for(int start= start_idx;start<n;start++){
                tmp.push_back(start+1);
                back(n,k,len+1,start+1);
                tmp.pop_back();
            }
        }

    };