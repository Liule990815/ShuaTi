#include <iostream>
using namespace std;
/*
https://www.nowcoder.com/practice/440f16e490a0404786865e99c6ad91c9
*/

int main() {
    int a = 0;
    cin >> a;
    int cnt = 0;
    while(a){
        int b = a % 2;
        if(b == 1){cnt++;}
        a = a / 2;
    }
    cout << cnt << endl;
}