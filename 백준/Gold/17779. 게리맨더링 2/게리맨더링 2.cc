#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n, res = 1e9;
int graph[21][21];
int people[5];

int find_area(int i, int j, int x, int y, int d1, int d2) {
	if (i < x) {
		if (j <= y) {
			return 0;
		}
		else {
			return 1;
		}
	}
	else if (x <= i && i < x + d1 && j < y - (i - x)) {
		return 0;
	}
	else if (x <= i && i <= x + d2 && j > y + (i - x)) {
		return 1;
	}
	else if (x + d1 <= i && i <= x + d1 + d2 && j < (y - d1 + d2) - (x + d1 + d2 - i)) {
		return 2;
	}
	else if (x + d2 < i && i <= x + d1 + d2 && j > (y - d1 + d2) + (x + d1 + d2 - i)) {
		return 3;
	}
	else if (i > x + d1 + d2) {
		if (j < (y - d1 + d2)) {
			return 2;
		}
		else {
			return 3;
		}
	}
	else {
		return 4;
	}
}

int func(int x, int y, int d1, int d2) {
	memset(people, 0, sizeof(people));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int area = find_area(i, j, x, y, d1, d2);
			people[area] += graph[i][j];
		}
	}
	int mn = 1e9;
	int mx = 0;
	for (int i = 0; i < 5; i++) {
		mx = max(mx, people[i]);
		mn = min(mn, people[i]);
	}
	return mx - mn;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> graph[i][j];
		}
	}
	for (int x = 1; x < n - 1; x++) {
		for (int y = 2; y < n; y++) {
			for (int d1 = 1; y - d1 > 0; d1++) {
				for (int d2 = 1; y + d2 <= n && x + d1 + d2 <= n; d2++) {
					res = min(func(x, y, d1, d2), res);
				}
			}
		}
	}
	cout << res;
	return 0;
}