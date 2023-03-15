#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    long n;
    cin >> n;
    if(n == 1){
        return -1;
    }
    if(n > 1){
        for(int i = 2;i <= sqrt(n);i++){
        while(n % i == 0){
            n /= i;
            cout << i << ' ';
        } //质数分解法，最后n为1，或者一个大于sqrt(n)的质数
        
    }
    if(n > 1){ //直接输出这个质数
        cout << n << ' ';
    }
        return 0;
    }
}