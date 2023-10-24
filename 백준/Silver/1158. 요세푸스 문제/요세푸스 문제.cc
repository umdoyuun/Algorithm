#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int n, k;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	cout << '<';
	while (!q.empty()) {
		for (int i = 1; i < k; i++) {
			q.push(q.front());
			q.pop();
		}
		cout << q.front();
		if (q.size() > 1)
			cout << ", ";
		q.pop();
	}
	cout << '>';
	return 0;
}