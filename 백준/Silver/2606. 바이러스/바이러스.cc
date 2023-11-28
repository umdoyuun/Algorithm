#include <iostream>
#include <vector>
using namespace std;

vector<int> v[101];
bool visit[101];
int n, m, result;

void dfs(int x){
	visit[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (visit[y]) continue;
		result++;
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
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	cout << result;
	return 0;
}