#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
  public:
    string addBinary(string a, string b) {
        string ans;
        int l1 =a.size()-1,l2=b.size()-1,carry =0;
        while(l1>=0 || l2>=0){
            int total = carry;
            if(l1>=0)
                total += a[l1] -'0';
            if(l2>=0){
                total += b[l2] - '0';
            }
            carry = (total)/2;
            ans.push_back(total%2+'0');
            l1--;
            l2--;
        }
        if(carry){
            ans.push_back(carry+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    Solution s;
    cout<<s.addBinary("11", "1")<<endl;
}