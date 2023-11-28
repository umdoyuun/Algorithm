#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
int arr[101];
vector<int> result;
bool visit[101];

void bfs(int sx) {
	memset(visit, 0, sizeof(visit));
	queue<int> q;
	q.push(sx);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		int y = arr[x];
		if (visit[y]) continue;
		q.push(y);
		visit[y] = true;
	}
	if (visit[sx]) result.push_back(sx);
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		arr[i] = x;
	}
	for (int i = 1; i <= n; i++) {
		bfs(i);
	}
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	return 0;
}