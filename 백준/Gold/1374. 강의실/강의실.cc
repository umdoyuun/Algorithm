#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct lecture {
	int x, s, e;
};

bool cmp(lecture a, lecture b) {
	if (a.s == b.s) {
		return a.e < b.e;
	}
	return a.s < b.s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<lecture> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].s >> v[i].e;
	}
	sort(v.begin(), v.end(), cmp);
	int res = 0;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		pq.push( -v[i].e);
		while (-pq.top() <= v[i].s) {
			pq.pop();
		}
		res = max((int)pq.size(), res);
	}
	cout << res << '\n';
	return 0;
}