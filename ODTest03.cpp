#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

/*
求长度位N的数列的最小长度位L的几何平均值最大的子数列，返回子数列的起始位置以及长度
如输入：  3 2
		 2
		 2
		 3
输出：	  1 2	
*/

//求下标从a到b的vec[i]几何平均值
double get_pow(int a, int b, vector<double>& vec, int n) {
	if (b > n) {
		return -1;
	}
	double pow1 = 1;
	double t = double(1)/double(b - a + 1);
	for (int i = a; i <= b; i++) {
		pow1 = pow1 * vec[i];
		//cout << pow1 << endl;
	}
	double res = pow(pow1, t);
	return res;
}

int main() {
	int N = 0;
	int L = 0;
	double max = 0;
	double pow = 1;
	int pos = 0;
	int len = 0;
	cin >> N >> L;
	vector<double> vec(N, 0);
	for (int i = 0; i < N; i++) {
		double temp = 0;
		cin >> temp;
		vec[i] = temp;
	}
	for (int i = 0; i < N - L + 1; i++) {
		for (int j = i + L - 1; j < N; j++) {
			if (get_pow(i, j, vec, N) > max) {
				max = get_pow(i, j, vec, N);
				pos = i;
				len = j - i + 1;
			}
		}
	}
	cout << pos << " "<< len << endl;
	/*for (int i = 0; i < N - L + 1; i++) {
		cout << i << ":" << N - L + 1 << "," << get_pow(i, i + L - 1, vec, N) << endl;
	}*/
}


//int a = 0;
//	int b = 0;
//	int c = 0;
//	cin >> a >> b >> c;
//	double x = a * b * c;
//	double y = double(1) / double(3);
//	cout << pow(x, y);