#include <iostream>
#include <queue>
using namespace std;

int n, k;
char graph[2][100001];
bool visit[2][100001];

int dx[3] = { 1, -1, 0 };
int dloc[3] = { 0, 0, 1 };

struct node {
	int loc, x, t;
};

int bfs() {
	queue<node> q;
	q.push({ 0, 0, 0 });
	visit[0][0] = true;
	while (!q.empty()) {
		int loc = q.front().loc;
		int x = q.front().x;
		int t = q.front().t;
		q.pop();
		for (int i = 0; i < 3; i++) {
			int nx = x + dx[i];
			int nloc = (loc + dloc[i]) % 2;
			if (nx >= n) return 1;
			if (nx <= t || graph[nloc][nx] == '0' || visit[nloc][nx]) continue;
			visit[nloc][nx] = true;
			q.push({ nloc, nx, t + 1 });
		}
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	dx[2] = k;
	for (register int i = 0; i < n; i++) {
		cin >> graph[0][i];
	}
	for (register int i = 0; i < n; i++) {
		cin >> graph[1][i];
	}
	cout << bfs() << '\n';
	return 0;
}