#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, result;
vector<pair<int, int>> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, 1 });
		v.push_back({ y, 0 });
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int flag = v[i].second;
		if (flag == 1)
			cnt++;
		else
			cnt--;
		result = max(result, cnt);
	}
	cout << result;
	return 0;
}