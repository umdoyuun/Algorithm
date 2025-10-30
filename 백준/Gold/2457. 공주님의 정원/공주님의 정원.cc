#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct flower {
	int sm, sd, em, ed;
	bool operator<(const flower& other) const {
		if (em == other.em) {
			return ed < other.ed;
		}
		return em < other.em;
	}
};
flower f[100001];

bool cmp(flower a, flower b) {
	if (a.sm == b.sm) {
		if (a.sd == b.sd) {
			if (a.em == b.em) {
				return a.ed > b.ed;
			}
			return a.em > b.em;
		}
		return a.sd < b.sd;
	}
	return a.sm < b.sm;
}

int main() {
	int m = 3, d = 1, n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		f[i] = { sm, sd, em, ed };
	}
	sort(f, f + n, cmp);
	
	priority_queue<flower> pq;
	for (int i = 0; i < n; i++) {
		if (m > 12) {
			break;
		}
		if (m < f[i].sm || (m == f[i].sm && d < f[i].sd)) {
			if (!pq.empty()) {
				//cout << pq.top().sm << ' ' << pq.top().sd << ' ' << pq.top().em << ' ' << pq.top().ed << '\n';
				m =pq.top().em;
				d = pq.top().ed;
				res++;
			}
			while (!pq.empty()) {
				pq.pop();
			}
		}
		if (m > f[i].sm || (m == f[i].sm && d >= f[i].sd)) {
			pq.push(f[i]);
		}
		
	}
	if (!pq.empty() && m < 12) {
		res++;
		m = pq.top().em;
		d = pq.top().ed;
	}
	if (m < 12) res = 0;
	cout << res << '\n';
	return 0;
}