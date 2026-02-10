#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int scv[3];
int visit[61][61][61];

class node {
public:
	int cnt, x, y, z;
};

int attack[6][3] = {
	{9, 3, 1},
	{9, 1, 3},
	{3, 1, 9},
	{3, 9, 1},
	{1, 3, 9},
	{1, 9, 3}
};

int bfs() {
	queue<node> q;
	q.push({ 0, scv[0], scv[1], scv[2] });
	visit[scv[0]][scv[1]][scv[2]] = true;
	while (!q.empty()) {
		int cnt = q.front().cnt;
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		q.pop();
		if (!x && !y && !z) return cnt;
		for (int i = 0; i < 6; i++) {
			int nx = max(0, x - attack[i][0]);
			int ny = max(0, y - attack[i][1]);
			int nz = max(0, z - attack[i][2]);
			if (visit[nx][ny][nz]) continue;
			visit[nx][ny][nz] = true;
			q.push({ cnt + 1, nx, ny, nz });
		}
	}
	return 0;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	vector<int> sv;
	for (int i = 0; i < n; i++) {
		cin >> scv[i];
	}
	int res = bfs();
	cout << res << '\n';
	return 0;
}