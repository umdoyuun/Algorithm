#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 1005

int n, m, res;
vector<int> v[MAX];
int d[MAX];
bool visit[MAX];

bool dfs(int x) {
	if (visit[x]) return false;
	visit[x] = true;
	for (int y : v[x]) {
		if (d[y] == -1) {
			d[y] = x;
			return true;
		}
	}
	for (int y : v[x]) {
		if (dfs(d[y])) {
			d[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int s, x;
		cin >> s;
		for (int j = 0; j < s; j++) {
			cin >> x;
			v[i].push_back(x);
		}
	}
	memset(d, -1, sizeof(d));
	for (int i = 0; i < n; i++) {
		fill(visit, visit + n, false);
		if (dfs(i)) res++;
		fill(visit, visit + n, false);
		if (dfs(i)) res++;
		if (res == m) break;
	}
	cout << res << '\n';
	return 0;
}