class Solution {
  public:
   // Brian Kernighan 算法
    int rangeBitwiseAnd(int left, int right) {
        // 直到 right <= left，即为公共前缀
        while(left<right){
            right = right&(right-1);
        }
        return right;
    }

    // 寻找公共前缀
    int rangeBitwiseAnd1(int left, int right) {
        int shift=0;
        while(left<right){
            left>>=1;
            right>>=1;
            shift++;
        }
        return left<<shift;
    }
};

int main(){
    Solution s;
    int l=3,r=4;
    s.rangeBitwiseAnd(l,r);
}