#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int num = 0;
	int sum = 0;
	while (cin >> num && num) {
		sum = 0;    //记录喝汽水的数量
		int remain = num;   //记录瓶子数量
		while (remain > 2) {
			sum += remain / 3;  //喝汽水
			remain = (remain / 3) + (remain % 3);
		}
		if (remain == 2) { //剩两个瓶子的时候借一个
			sum++;
		}
		cout << sum << endl;
	}
	return 0;
}