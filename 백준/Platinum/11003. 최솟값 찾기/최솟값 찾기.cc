#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

deque<pair<int, int>> dq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, l, x;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (dq.empty())
			dq.push_back({ x, i });
		else {
			if (dq.front().second < i - l + 1) dq.pop_front();
			while (!dq.empty() && x < dq.back().first) {
				dq.pop_back(); 
			}
			dq.push_back({ x, i });
		}
		cout << dq.front().first << ' ';
	}
	return 0;
}
