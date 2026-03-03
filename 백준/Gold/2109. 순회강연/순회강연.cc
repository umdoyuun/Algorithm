#include <iostream>
#include <queue>
using namespace std;

int n, res;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	priority_queue<pair<int, int>> pq;
	priority_queue<int> pq2;
	cin >> n;
	int p, d;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		pq.push({ d, p });
	}
	int idx = 10002;
	while (!pq.empty()) {
		idx = pq.top().first;
		while (!pq.empty()) {
			d = pq.top().first;
			p = pq.top().second;
			if (d != idx) break;
			pq2.push(p);
			pq.pop();
		}
		while (!pq2.empty() && d != idx) {
			res += pq2.top();
			pq2.pop();
			idx--;
		}		
	}
	while (!pq2.empty() && idx) {
		res += pq2.top();
		pq2.pop();
		idx--;
	}
	cout << res << '\n';
	return 0;
}