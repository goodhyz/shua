
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n1 =ransomNote.size(),n2=magazine.size();
        if(n1>n2){
            return false;
        }
        vector<int> map(26,0);
        for(int i=0;i<n2;i++){
            map[magazine[i]-'a']++;
        }
        for(int i=0;i<n1;i++){
            int curVal = --map[ransomNote[i]-'a'];
            if(curVal<0){
                return false;
            }
        }
        return true;
    }
};