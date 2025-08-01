class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int l1=0,l2=0;
            while(l1<s.size() && l2<t.size()){
                if(s[l1] == t[l2]){
                    l1++;
                }
                l2++;
            }
            return l1 == s.size();

        }
    };