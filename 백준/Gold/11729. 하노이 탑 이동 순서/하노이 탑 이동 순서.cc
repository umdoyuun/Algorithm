#include <iostream>
#include <vector>
using namespace std;

int n, cnt;

vector<pair<int, int>> res;

void func(int x, int y, int k) {
	if (k == 0) {
		cnt++;
		res.push_back({ x, y });
	}
	else {
		func(x, (6 - x - y), k - 1);
		cnt++;
		res.push_back({ x, y });
		func((6 - x - y), y, k - 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	func(1, 3, n - 1);
	cout << cnt << '\n';
	for (auto x : res) {
		cout << x.first << ' ' << x.second << '\n';
	}
	return 0;
}