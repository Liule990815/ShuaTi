#include <iostream>
#include <cmath>
using namespace std;

int main() {
    //接收输入
    string str;
    int res = 0;
    getline(cin, str);
    str.erase(str.begin(), str.begin()+2);
    //cout << str <<endl;
    for(int i  = 0;i < str.length();i++){
        int k = str.length() - 1 -i;
        switch(str[i]){
            case 'A': res += pow(16, k) * 10;break;
            case 'B': res += pow(16, k) * 11;break;
            case 'C': res += pow(16, k) * 12;break;
            case 'D': res += pow(16, k) * 13;break;
            case 'E': res += pow(16, k) * 14;break;
            case 'F': res += pow(16, k) * 15;break;
            default:  res += pow(16, k) * int(str[i] - '0');break;
        }
    }
    cout << res << endl;
}