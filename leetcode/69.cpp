class Solution {
    public:
        int mySqrt1(int x) {
            long long i=0;
            while(i<=x){
                if(i*i<=x&&(i+1)*(i+1)>x)break;
                i++;
            }
            return i;
        }
        int mySqrt1(int x) {
            long long l=0,r=x,mid;
            while(l<=r){
                mid =(l+rd)/2;
                if(mid*mi<=x){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            return mid;
        }
    };