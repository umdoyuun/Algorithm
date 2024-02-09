#include <iostream>
using namespace std;

int n, m;
int map[1001][1001];
int mx, my, Min = 0x7fffffff;

void func() {
	int x = 0, y = 0;
	while (x != mx && x + 1 != mx) {
		for (int i = 0; i < m - 1; i++) {
			cout << 'R';
		}
		cout << 'D';
		for (int i = 0; i < m - 1; i++) {
			cout << 'L';
		}
		cout << 'D';
		x += 2;
	}
	bool flag = true;
	while (y < m) {
		if (y != my) {
			if (flag) {
				cout << 'D';
				flag = false;
			}
			else {
				cout << 'U';
				flag = true;
			}
		}
		
		if (y != m - 1) {
			cout << 'R';
		}
		y++;
	}
	x += 2;
	if (x < n) {
		cout << 'D';
	}
	while (x < n) {
		for (int i = 0; i < m - 1; i++) {
			cout << 'L';
		}
		cout << 'D';
		for (int i = 0; i < m - 1; i++) {
			cout << 'R';
		}
		x += 2;
		if (x < n) {
			cout << 'D';
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if ((i + j) % 2 == 1) {
				if (Min > map[i][j]) {
					Min = map[i][j];
					mx = i;
					my = j;
				}
			}
		}
	}

	if (n % 2 == 1) {
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < m - 1; j++) {
				cout << 'R';
			}
			cout << 'D';
			for (int j = 0; j < m - 1; j++) {
				cout << 'L';
			}
			cout << 'D';
		}
		for (int i = 0; i < m - 1; i++) {
			cout << 'R';
		}
	}
	else if (m % 2 == 1) {
		for (int i = 0; i < m / 2; i++) {
			for (int j = 0; j < n - 1; j++) {
				cout << 'D';
			}
			cout << 'R';
			for (int j = 0; j < n - 1; j++) {
				cout << 'U';
			}
			cout << 'R';
		}
		for (int i = 0; i < n - 1; i++) {
			cout << 'D';
		}
	}
	else {
		func();
	}
	return 0;
}