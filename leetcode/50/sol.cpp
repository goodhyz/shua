#include <iostream>
#include <chrono>

class Solution {
  public:
   // 暴力法
    double myPow1(double x, int n1) {
        double n = double(n1);
        if (n == 0 || x == 1)
            return 1;
        bool flag = false;
        if (n < 0) {
            flag = true;
            n = -1 * n;
        }
        double total;
        if (n > 0) {
            total = x;
            while (--n) {
                total = total * x;
            }
        }
        if (flag)
            return 1 / total;
        return total;
    }

    //快速幂方法
    double myPow(double x, int n) {
        long long N=n;
        return N>=0 ?quickPow(x,N):1/quickPow(x,-N);
    }
    double quickPow(double x , long long N){
        if(N==0)return 1;
        double y = quickPow(x,N/2);
        std::cout<<"1";
        return (N%2==0)?y*y:y*y*x;
    }

    //做了很多次重复计算，2^logN 复杂度
    double quickPow2(double x , long long N){
        if(N==0)return 1;
        std::cout<<"1";
        return (N%2==0)?quickPow2(x,N/2)*quickPow2(x,N/2):quickPow2(x,N/2)*quickPow2(x,N/2)*x;
    }
};


int main(){
    Solution  s;
    double x = 2.000;
    int n = 4;

    auto start = std::chrono::high_resolution_clock::now();
    double result = s.myPow(x, n);
    auto end = std::chrono::high_resolution_clock::now();

    // std::chrono::duration<double> duration = end - start;
    // std::cout << "Result: " << result << std::endl;
    // std::cout << "Time taken by myPow: " << duration.count() << " seconds" << std::endl;

    return 0;
}