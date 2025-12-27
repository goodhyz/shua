// 给定一个仅包含数字的字符串，将其解析为合法 IP 地址，输出符合要求的 IP 地址个数。 合法的 IP 地址要求：包含四部分，每部分的范围为 0 ~ 255，且不能有前导 0，如 192.168.1.1 为合法，192.168.01.1 未非法。
// 255255255255 输出1
#include<iostream>
#include<string>

using namespace std;

bool isValid(const string& s) {
    // 长度不能为0或大于3
    if (s.empty() || s.length() > 3) {
        return false;
    }
    // 长度大于1时，不能有前导零
    if (s.length() > 1 && s[0] == '0') {
        return false;
    }
    // 数值不能超过255
    if (stoi(s) > 255) {
        return false;
    }
    return true;
}

int count(string input) {
    int cnt = 0;
    int len = input.size();
    if(len >12 or len < 4){
        return 0;
    }
    for (int i = 0; i < len-3; i++){
        for (int j = i+1; j < len-2; j++){
            for (int k = j+1; k < len-1; k++){
                string a = input.substr(0, i+1);
                string b = input.substr(i+1, j-i);
                string c = input.substr(j+1, k-j);
                string d = input.substr(k+1);
                
                if(isValid(a) and isValid(b) and isValid(c) and isValid(d)){
                    cnt++;
                }
            }
        }
    }
    return cnt;
}


int main() {
    string input;
    while(cin>>input){
        cout<<count(input)<<endl;
    }
    return 0;
}