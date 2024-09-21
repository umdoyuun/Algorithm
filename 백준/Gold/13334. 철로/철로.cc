#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;
int n, d, res;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		v.push_back({ x, y });
	}
	cin >> d;
	sort(v.begin(), v.end(), cmp);
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int s = v[i].first;
		int e = v[i].second;
		if (e - s > d) continue;
		pq.push(-s);
		while (!pq.empty()) {
			int ss = -pq.top();
			if (e - ss > d) pq.pop();
			else break;
		}
		res = max(res, (int)pq.size());
	}
	cout << res << '\n';
	return 0;
}