#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, result;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		pq.push({ s, 1 });
		pq.push({ t, 0 });
	}
	int cnt = 0;
	while (!pq.empty()) {
		int x = pq.top().first;
		int flag = pq.top().second;
		pq.pop();
		if (flag == 1) {
			cnt++;
			result = max(cnt, result);
		}
		else cnt--;
	}
	cout << result;
	return 0;
}