#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;
/*
https://www.nowcoder.com/practice/03ba8aeeef73400ca7a37a5f3370fe68
*/
bool is_brother(string& s, string& t){ //判断是否为兄弟单词
    if(s == t){
        return false;
    }
    int a_s[26] = {0};
    for(int i = 0;i < s.length();i++){
        a_s[s[i] - 'a']++;
    }
    int a_t[26] = {0};
    for(int i = 0;i < t.length();i++){
        a_t[t[i] - 'a']++;
    }
    for(int i = 0;i < 26;i++){
        if(a_s[i] == a_t[i]){
            continue;
        }else{
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    map<string, int>mp;
    int cnt = 0;
    string check_str;
    int check_int;
    vector<string> vec;
    while(n--){
        string str;
        cin >> str;
        vec.push_back(str);
    }
    cin >> check_str;
    cin >> check_int;
    for(int i = 0;i < vec.size();i++){
        if(is_brother(vec[i], check_str)){
            cnt++;
            mp[vec[i]] ++;
        }
    }
    auto a = mp.begin();
    int cnt_map = 1;
    // for(a;a != mp.end();a++){
    //     cout << a->first << ": " << a->second << endl;
    // }

    while(cnt_map < check_int && a->second){ //兄弟单词字典有特殊情况：1.空；2.字典顺序下有重复单词也要计数。
        if(a->second > 1){
            cnt_map += a->second;
            if(cnt_map < check_int){
                a++;
                cnt_map++;
            }
            //cout << cnt_map << endl;
        }else{
            cnt_map++;
            a++;
        }
    }
    cout << cnt << endl;
    if(check_int > cnt){
        cout << endl;
    }else{
        cout << a->first << endl;
    }
}
// 64 位输出请用 printf("%lld")