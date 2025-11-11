#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, cnt = 0;
	cin >> n >> m;
	vector<int> v(m + 1, 0);
	for (int i = 2; i <= m; i++) {
		v[i] = i;
	}
	for (int i = 2; i * i <= m; i++) {
		if (v[i] == 0) continue;
		for (int j = 2 * i; j <= m; j += i) {
			if (v[j] == 0) continue;
			else v[j] = 0;
		}
	}
	for (int i = n; i <= m; i++) {
		if (v[i] != 0) cout << v[i] << '\n';
	}
	return 0;
}