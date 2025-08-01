#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // for(const int& num:nums){
        //     s.insert(num);
        // }
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        /**
        trick: 当哈希表中存在比当前数字小1的数时，跳过该数字
        我们只需要对一段序列中最小的那个数字进行计算

         */
        // 直接访问set就行,不需要访问nums了
        for (const int &num : s)
        {
            if (s.count(num - 1))
                continue;
            int tmp = num;
            int len_of_sub = 1;
            while (s.count(tmp + 1) != 0)
            {
                len_of_sub++;
                tmp++;
            }
            longest = max(longest, len_of_sub);
        }
        return longest;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s;
    for(int num:nums)
        s.insert(num);
    
    int ret = 0;
    for(auto& i:s)
    {
        if(s.find(i-1) != s.end()) continue;
        int j = i+1,val = 1;
        while(s.find(j) != s.end())
        {
            j++;
            val++;
        }
        ret = max(ret,val);
    }

    return ret;
    }
};