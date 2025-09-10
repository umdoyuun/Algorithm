#include <iostream>
#include <vector>
using namespace std;

int n, m, s, res;
vector<int> v[100001];
bool visit[100001];

void dfs(int x) {
	for (int y : v[x]) {
		if (visit[y]) continue;
		visit[y] = true;
		res++;
		dfs(y);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		v[y].push_back(x);
	}
	cin >> s;
	visit[s] = true;
	dfs(s);
	cout << res << '\n';
	return 0;
}