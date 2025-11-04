#include <iostream>
#include <algorithm>
using namespace std;

int n, m, res = 1e9;
char board[51][51];

void check(int x, int y){
	int cnt[2] = { 0, };
	for (int i = x; i < x + 8; i++) {
		for (int j = y; j < y + 8; j++) {
			if ((i + j) % 2) {
				if (board[i][j] == 'W') {
					cnt[0]++;
				}
				else {
					cnt[1]++;
				}
			}
			else {
				if (board[i][j] == 'B') {
					cnt[0]++;
				}
				else {
					cnt[1]++;
				}
			}
		}
	}
	res = min(res, cnt[0]);
	res = min(res, cnt[1]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	int cnt[2] = { 0, };
	for (int i = 0; i <= n - 8; i++) {
		for (int j = 0; j <= m - 8; j++) {
			check(i, j);
		}
	}
	cout << res;
	return 0;
}