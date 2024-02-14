#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, b_res, w_res;
vector<pair<int, int>> white;
vector<pair<int, int>> black;

int dx[4] = { -1, 1, 1, -1 };
int dy[4] = { 1, 1, -1, -1 };

void b_dfs(int idx, int cnt, bool visit[10][10]) {
	if (idx >= black.size()) {
		b_res = max(b_res, cnt);
		return;
	}
	int x = black[idx].first;
	int y = black[idx].second;
	if (visit[x][y]) {
		b_dfs(idx + 1, cnt, visit);
		return;
	}
	b_dfs(idx + 1, cnt,visit);
	bool tmp[10][10] = {false, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = visit[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			int nx = x + j * dx[i];
			int ny = y + j * dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
			tmp[nx][ny] = true;
		}
	}
	b_dfs(idx + 1, cnt + 1, tmp);
}

void w_dfs(int idx, int cnt, bool visit[10][10]) {
	if (idx >= white.size()) {
		w_res = max(w_res, cnt);
		return;
	}
	int x = white[idx].first;
	int y = white[idx].second;
	if (visit[x][y]) {
		w_dfs(idx + 1, cnt, visit);
		return;
	}
	bool tmp[10][10] = { false, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			tmp[i][j] = visit[i][j];
		}
	}
	w_dfs(idx + 1, cnt, visit);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			int nx = x + j * dx[i];
			int ny = y + j * dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
			tmp[nx][ny] = true;
		}
	}
	w_dfs(idx + 1, cnt + 1, tmp);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			if (x == 1) {
				if ((i + j) % 2 == 0) white.push_back({ i, j });
				else black.push_back({ i, j });
			}
		}
	}
	bool visit[10][10] = { false, };
	b_dfs(0, 0, visit);
	w_dfs(0, 0, visit);
	cout << b_res + w_res;
	return 0;
}