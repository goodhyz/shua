#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t result=0;
            for(int i=0;i<32;i++){
                result|=(n&1)<<(31-i);
                n=n>>1;
            }
            return result;
        }
        uint32_t reverseBits(uint32_t n) {
            n = n>>1 & 0x55555555 | (n & 0x55555555)<<1;
            n = n>>2 & 0x33333333 | (n & 0x33333333)<<2;
            n = n>>4 & 0x0f0f0f0f | (n & 0x0f0f0f0f)<<4;
            n = n>>8 & 0x00ff00ff | (n & 0x00ff00ff)<<8;
            return n>>16|n<<16;
        }
    };