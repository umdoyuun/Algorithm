#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int r, c, n, res;
vector<int> v[301];
int d[301];
bool arr[301][301], visit[301];;

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
	cin >> r >> c >> n;
	
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = true;
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j]) continue;
			v[i].push_back(j);
		}
	}
	for (int i = 1; i <= r; i++) {
		memset(visit, false, sizeof(visit));
		if (dfs(i)) res++;
	}
	cout << res << '\n';
	return 0;
}