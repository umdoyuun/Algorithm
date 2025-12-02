#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define x first
#define y second

int n, m;
vector<pair<int, int>> tar;
set<pair<int, int>> s;
pair<int, int> tmp;

pair<int, int> find_star(pair<int, int> std_star) {
	pair<int, int> ret = { std_star.x - tmp.x, std_star.y - tmp.y };
	for (auto it : tar) {
		if (s.find({ std_star.x + it.x, std_star.y + it.y }) == s.end()) {
			return { -1, -1 };
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (!i) {
			tmp.x = a;
			tmp.y = b;
		}
		tar.push_back({ a - tmp.x, b - tmp.y });
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		s.insert({ a, b });
	}
	pair<int, int> res;
	for (auto it : s) {
		res = find_star({ it });
		if (res.x != -1) break;
	}
	cout << res.x << ' ' << res.y;
	return 0;
}