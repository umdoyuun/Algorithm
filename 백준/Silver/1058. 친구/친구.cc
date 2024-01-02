#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int n, result;
char map[51][51];
bool visit[51][51];

void bfs(int s) {
	queue<pair<int, int>> q;
	q.push({ s, 0 });
	int friends = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cnt == 2) continue;
		for (int i = 0; i < n; i++) {
			if (map[x][i] == 'Y' && !visit[s][i]) {
				visit[s][i] = true;
				friends++;
				q.push({ i, cnt + 1 });
			}
		}
	}
	result = max(result, friends);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		visit[i][i] = true;
		bfs(i);
	}
	cout << result;
	return 0;
}