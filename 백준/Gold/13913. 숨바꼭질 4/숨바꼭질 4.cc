#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n, k;
int visit[100001];
int par[100001];

bool check(int x) {
	if (x < 0 || x > 100000) return false;
	return true;
}

int bfs() {
	queue<int> q;
	visit[n] = 1;
	q.push(n);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (x == k) return visit[x] - 1;
		if (check(x * 2) && !visit[x * 2]) {
			q.push(x * 2);
			visit[x * 2] = visit[x] + 1;
			par[x * 2] = x;
		}
		if (check(x + 1) && !visit[x + 1]) {
			q.push(x + 1);
			visit[x + 1] = visit[x] + 1;
			par[x + 1] = x;
		}
		if (check(x - 1) && !visit[x - 1]) {
			q.push(x - 1);
			visit[x - 1] = visit[x] + 1;
			par[x - 1] = x;
		}
	}
	return 0;
}

stack<int> path;

void find_path() {
	int cur = k;
	while (cur != n) {
		path.push(cur);
		cur = par[cur];
	}
	path.push(cur);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	int ret = bfs();
	find_path();
	cout << ret << '\n';
	while(!path.empty()){
		int x = path.top();
		path.pop();
		cout << x << ' ';
	}
	return 0;
}