#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1001;

struct node {
	int cnt, copy, sec;
};
int s;
bool visited[MAX][MAX];

int bfs() {
	queue<node> q; 
	q.push({ 1, 0, 0 });
	visited[1][0] = true;
	while (!q.empty()) {
		node cur = q.front();
		q.pop();
		if (cur.cnt == s) return cur.sec;
		if (!visited[cur.cnt][cur.cnt]) {
			visited[cur.cnt][cur.cnt] = true;
			q.push({ cur.cnt, cur.cnt, cur.sec + 1 });
		}
		if (cur.copy > 0) {
			int nc = cur.cnt + cur.copy;
			if (nc < MAX && !visited[nc][cur.copy]) {
				visited[nc][cur.copy] = true;
				q.push({ nc, cur.copy, cur.sec + 1 });
			}
		}
		int nc = cur.cnt - 1;
		if (nc > 0 && !visited[nc][cur.copy]) {
			visited[nc][cur.copy] = true;
			q.push({ nc, cur.copy, cur.sec + 1 });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	int res = bfs();
	cout << res << '\n';
	return 0;
}