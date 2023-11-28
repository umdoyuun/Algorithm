#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int n;
int par[100005];
vector<int> v[100005];
bool visit[100005];

void dfs(int x) {
	visit[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int nx = v[x][i];
		if (visit[nx]) continue;
		par[nx] = x;
		dfs(nx);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int a, b;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= n; i++) {
		cout << par[i] << '\n';
	}
	return 0;
}