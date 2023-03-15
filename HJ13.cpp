#include<string>
#include<iostream>
using namespace std;

int main() {
    string str, res; 
    while(cin >> str) { //cin >> 遇到空格自动断开
        str += " " +res;
        res = str;
    }
    cout << res << endl;
    return 0;
}
