#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            if(intervals.size()<=1)return intervals;
            //先对intervals排序
            sort(intervals.begin(),intervals.end());
            vector<vector<int>> res;
            for(const auto & interval:intervals){
                if(res.empty()||res.back()[1]<interval[0]){
                    res.push_back(interval);
                }else{
                    res.back()[1]=max(res.back()[1],interval[1]);
                }
            }
            return res;  
        }

        void quickSort(vector<vector<int>>& p,int l,int r){
            if(l>=r)return;
            int pi = p[r][0];
            // l r-1
            int left =l,right = r;
            while(left<right){
                while(left<right&&p[left][0]<=pi)left++; //找第一个大于pivot的元素 找不到left将达到right
                while(left<right&&p[right][0]>=pi)right--; // 找第一个小于pivot的元素 找不到right将达到left
                swap(p[left],p[right]); 
            }
            swap(p[r],p[left]);
            quickSort(p,l,left-1);
            quickSort(p,left+1,r);
        }
    };