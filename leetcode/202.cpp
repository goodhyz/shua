#include<vector>
#include<set>
using namespace std;

class Solution {
    public:
        /*
        哈希集合方法
        */
        bool isHappy(int n) {
            set<int> hash_set; //用unordered_set可以吗
            while(true){
                n = getSum(n);
                auto it = hash_set.find(n);
                if (it!=hash_set.end()){
                    return false;
                }
                if(n==1)return true;
                hash_set.insert({n});
            }
            return true;
        }
        int getSum(int n){
            int sum = 0;
            while (n > 0) {
                sum+=(n%10)*(n%10);  // 取出最后一位数字
                n = n / 10;  // 去掉最后一位数字
            }
            return sum;
        }

        /*
        快慢指针方法，其实是一个环形链表
        */
       bool isHappy1(int n) {
        int slow=n,fast=n;
        while(true){
            slow = getSum(n);
            fast = getSum(n);
            fast = getSum(n);
            if(slow == 1 or fast == 1)return true;
            if(slow == fast)return false;
        }
        return true;
    }
    };

    int main(){
        Solution s;
        s.isHappy(19);
    }