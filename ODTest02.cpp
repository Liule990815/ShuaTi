#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
/*
题目描述：给你一个行数m列数n，然后让你输入m*n矩阵A的元素的数值，然后生成一个矩阵B：
B[i,j]是A[i,j]到A中其他值相同的元素的位置的最小值；若找不到相同的值，则返回-1。
*/
using namespace std;
int get_dis(int x1, int y1, int x2, int y2) { //计算坐标之间的距离
	int dis_x = 0;
	int dis_y = 0;
	if (x1 > x2) dis_x = x1 - x2;
	else dis_x = x2 - x1;
	if (y1 > y2) dis_y = y1 - y2;
	else dis_y = y2 - y1;
	return dis_x + dis_y;
}
int get_min_dis(int x, int y, vector<pair<int, int>>& vec) {
	int min_dis = INT_MAX;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].first == x && vec[i].second == y) continue;
		else {
			if (min_dis > get_dis(x, y, vec[i].first, vec[i].second)) {
				min_dis = get_dis(x, y, vec[i].first, vec[i].second);
			}
		}
	}
	return min_dis;
}
int main() {
	map<int, vector<pair<int,int>>> mp;  //记录值，和她所在的坐标
	int r = 0;
	int c = 0;
	cin >> r;
	cin >> c;
	vector<vector<int>> vec(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> vec[i][j];
			//cout << i << "," << j << ":" << vec[i][j] << endl;
			mp[vec[i][j]].push_back(make_pair(i, j));
		}
	}
	//for (auto a = mp.begin(); a != mp.end(); a++) {
	//	cout << a->first << ":";
	//	for (int i = 0; i < a->second.size(); i++) {
	//		cout << "(" << (a->second[i]).first<< "," << (a->second[i]).second << ")";
	//	}
	//	cout << endl;
	//}
	cout << "[";
	for (int i = 0; i < r; i++) {
		cout << "[";
		for (int j = 0; j < c; j++) {
			if (mp[vec[i][j]].size() == 1) {
				cout << -1 << ", ";
			}
			else {
				if (j == c - 1) {
					cout << get_min_dis(i, j, mp[vec[i][j]]);
				}
				else {
					cout << get_min_dis(i, j, mp[vec[i][j]]) << ", ";
				}
			}
		}
		if (i == r - 1) {
			cout << "]";
		}
		else {
			cout << "], ";
		}
	}
	cout << "]";
}