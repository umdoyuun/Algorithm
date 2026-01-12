#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

deque<pair<int, int>> dq;
int n, t;

void func(int x) {
	if (!dq.empty()) {
		while (dq.back().first < x) {
			dq.pop_back();
			if (dq.empty()) break;
		}
	}
	if (dq.empty()) {
		cout << "0 ";
	}
	else {
		cout << dq.back().second << ' ';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		func(t);
		dq.push_back({t, i});
	}
	return 0;
}