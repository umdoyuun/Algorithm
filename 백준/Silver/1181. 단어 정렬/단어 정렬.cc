#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	string str;
	vector<string> str_v[51];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		str_v[str.size()].push_back(str);
	}
	for (int i = 1; i < 51; i++) {
		sort(str_v[i].begin(), str_v[i].end());
		str_v[i].erase(unique(str_v[i].begin(), str_v[i].end()), str_v[i].end());
		for (int j = 0; j < str_v[i].size(); j++) {
			cout << str_v[i][j] << '\n';
		}
	}
	return 0;
}