#include <iostream>
#include <queue>
#include <set>
using namespace std;

int n, m;
priority_queue<int> pq[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			pq[i].push(x);
		}
	}
	set<pair<int, int>> s;
	
	for (int i = 0; i < n; i++) {
		s.insert({ pq[i].top(), i });
		pq[i].pop();
	}
	int res = s.rbegin()->first - s.begin()->first;
	while (true) {
		int idx = s.rbegin()->second;
		s.erase(*s.rbegin());
		if (!pq[idx].empty()) {
			s.insert({ pq[idx].top(), idx });
			pq[idx].pop();
		}
		else {
			break;
		}
		res = min(res, s.rbegin()->first - s.begin()->first);
	}
	cout << res;
	return 0;
}