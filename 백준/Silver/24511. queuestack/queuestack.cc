#include <iostream>
#include <queue>
using namespace std;

int n, m;
int type[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	deque<int> dq;
	for (int i = 0; i < n; i++) {
		cin >> type[i];
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (!type[i]) {
			dq.push_front(x);
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		dq.push_back(x);
		cout << dq.front() << ' ';
		dq.pop_front();
	}
	return 0;
}