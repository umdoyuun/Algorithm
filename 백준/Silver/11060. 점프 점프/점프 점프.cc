#include <iostream>
#include <queue>
using namespace std;

int n;
bool visit[1001];
int arr[1001];

int bfs() {
	queue<pair<int, int>> q;
	q.push({0, 0});
	visit[0] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == n - 1) {
			return cnt;
		}
		for (int i = arr[x]; i > 0; i--) {
			int y = x + i;
			if (y >= n) continue;
			if (visit[y] || arr[y] == 0) continue;
			visit[y] = true;
			q.push({ y, cnt + 1 });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int res = bfs();
	cout << res;
	return 0;
}