#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k, res;
vector<int> v[1001];
vector<int> arr;
bool visit[1001];
int d[1001];

bool cmp(int x, int y) {
	return v[x].size() > v[y].size();
}

bool dfs(int x) {
	if (visit[x]) return false;
	visit[x] = true;

	for (int y : v[x]) {
		if (d[y] == 0 || dfs(d[y])) {
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
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		int s, x;
		cin >> s;
		for (int j = 0; j < s; j++) {
			cin >> x;
			v[i].push_back(x);
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		if (dfs(i)) res++;
		
	}
	for (int i = 1; i <= n; i++) {
		while (k) {
			memset(visit, false, sizeof(visit));
			if (dfs(i)) {
				res++;
				k--;
			}
			else break;
		}
		if (!k) break;
	}
	cout << res << '\n';
	return 0;
}