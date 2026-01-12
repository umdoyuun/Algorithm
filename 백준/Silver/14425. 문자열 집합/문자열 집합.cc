#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

map <string, bool> M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		M[str] = true;
	}
	for (int i = 0; i < m; i++) {
		string str;
		cin >> str;
		if (M[str])
			cnt++;
	}
	cout << cnt;
	return 0;
}