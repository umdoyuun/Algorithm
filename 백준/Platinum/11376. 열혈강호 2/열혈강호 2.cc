#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 1005

int n, m, res, t;
vector<int> v[MAX];
int d[MAX];
int visit[MAX];

bool dfs(int x) {
	if (visit[x] == t) return false;
	visit[x] = t;
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
		t++;
		if (dfs(i)) res++;
		t++;
		if (dfs(i)) res++;
		if (res == m) break;
	}
	cout << res << '\n';
	return 0;
}