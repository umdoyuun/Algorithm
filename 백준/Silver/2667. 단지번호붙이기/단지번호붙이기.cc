#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string map[26];
bool visit[26][26];
vector<int> res;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dfs(int x, int y) {
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (visit[nx][ny] || map[nx][ny] == '0') continue;
		visit[nx][ny] = true;
		ret += dfs(nx, ny);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j] && map[i][j] == '1') {
				visit[i][j] = true;
				res.push_back(dfs(i, j));
			}
		}
	}
	sort(res.begin(), res.end());

	cout << res.size() << '\n';
	for (auto x : res) {
		cout << x << '\n';
	}
}