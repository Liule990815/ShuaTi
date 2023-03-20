#include <iostream>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> random_number;
    while(N--){
        int n;
        cin >> n;
        random_number.insert(n);
    }
    for(auto c = random_number.begin();c != random_number.end();c++){
        cout << *c << endl; //注意这里要解引用
    }
}