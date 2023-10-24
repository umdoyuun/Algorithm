#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, cnt;
	string str;
	vector<string> str_v;
	cin >> n;
	cnt = n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		str_v.push_back(str);
	}
	sort(str_v.begin(), str_v.end());
	string pre = str_v[0];
	for (int i = 1; i < n; i++) {
		if (pre == str_v[i].substr(0, pre.size())) {
			cnt--;
		}
		pre = str_v[i];
	}
	cout << cnt;
	return 0;
}