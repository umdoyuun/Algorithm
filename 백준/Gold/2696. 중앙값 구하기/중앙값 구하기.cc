#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int n, mid, first, even, odd;
priority_queue<int, vector<int>, greater<int>> min_h;
priority_queue<int, vector<int>, less<int>> max_h;

void init() {
	min_h = priority_queue<int, vector<int>, greater<int>>();
	max_h = priority_queue<int, vector<int>, less<int>>();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int tc, T;
	cin >> T;
	for (tc = 1; tc <= T; ++tc) {
		init();
		cin >> n;
		if (n % 2 == 1) cout << n / 2 + 1 << '\n';
		else cout << n / 2 << '\n';
		int cnt = 0;

		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				cin >> first;
				mid = first;
				cout << mid << ' ';
				cnt++;
			}
			else if (i % 2 == 1) {
				cin >> odd;
				if (odd >= mid) {
					min_h.push(odd);
				}
				else {
					max_h.push(odd);
				}
				if (min_h.size() > max_h.size()) {
					max_h.push(mid);
					mid = min_h.top();
					min_h.pop();
				}
				else if (max_h.size() > min_h.size()) {
					min_h.push(mid);
					mid = max_h.top();
					max_h.pop();
				}
				cout << mid << ' ';
				cnt++;
				if (cnt == 10) {
					cout << '\n';
					cnt = 0;
				}
			}
			else if (i % 2 == 0) {
				cin >> even;
				if (even >= mid) {
					min_h.push(even);
				}
				else {
					max_h.push(even);
				}
			}
		}
		cout << '\n';
	}
	return 0;
}