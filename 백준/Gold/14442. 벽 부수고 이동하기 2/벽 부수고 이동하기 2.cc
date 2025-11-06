#include <iostream>
using namespace std;

int n, m, k;
int graph[1001][1001];
int visit[1001][1001][11];

int dx[4] = { 1, 0, -1 ,0 };
int dy[4] = { 0, 1, 0, -1 };

struct node {
	int x, y, key;
};
node q[1000001];
int s, e;
int bfs() {
	q[e++] = { 1, 1, 0 };
	visit[1][1][0] = 1;
	while (s != e) {
		node cur = q[s++];
		if (s == 1000001) s = 0;
		if (cur.x == n && cur.y == m) {
			return visit[n][m][cur.key];
		}
		for (int i = 0; i < 4; i++) {
			node next = { cur.x + dx[i], cur.y + dy[i], cur.key };
			if (next.x < 1 || next.y < 1 || next.x > n || next.y > m) continue;
			if (graph[next.x][next.y]) {
				if (next.key < k) {
					next.key++;
				}
				else continue;
			}
			if (visit[next.x][next.y][next.key]) continue;
			visit[next.x][next.y][next.key] = visit[cur.x][cur.y][cur.key] + 1;
			q[e++] = next;
			if (e == 1000001) e = 0;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	char c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c;
			graph[i][j] = c - '0';
		}
	}
	int res = bfs();
	cout << res << '\n';
	return 0;
}