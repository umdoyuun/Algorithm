#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, cnt = 0;
	string str;
	deque<char> dq;
	cin >> n >> m >> str;
	for (int i = 0; i < n; i++) {
		while (!dq.empty()) {
			if (dq.back() < str[i] && cnt < m) {
				dq.pop_back();
				cnt++;
			}
			else break;
		}
		dq.push_back(str[i]);
	}
	for (int i = 0; i < n - m; i++) {
		cout << dq[i];
	}
	return 0;
}