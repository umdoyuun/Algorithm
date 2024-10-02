#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, result = 0;
	
	cin >> n;
	vector<pair<int, int>> v(n * 2);
	for (register int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[i * 2] = { x, 1 };
		v[i * 2 + 1] = { y, 0 };
	}
	sort(v.begin(), v.end());
	register int cnt = 0;
	for (register int i = 0; i < n * 2; i++) {
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