#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

    //定义变量
    int n;
    vector<string> s;   //用vector存储n个字符串
    //数据输入
    cin >> n; 
    //s.resize(n);
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        s.push_back(str);
    }
    //数据处理,冒泡排序
    for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {   //用vecrot，下标从1开始
            if (s[j] < s[j + 1]) {
                //string s_temp = s[j + 1];
                //s[j + 1] = s[j];
                //s[j] = s_temp;
                swap(s[j], s[j+1]);
            }
        }
        cout << s[i] << endl;
    }
}
