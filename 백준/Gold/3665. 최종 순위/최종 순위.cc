#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
int arr[501];
int order[501];
int inDegree[501];
bool visit[501][501];
vector<int> v[501];

void init() {
	for (int i = 1; i <= n; i++) {
		v[i].clear();
	}
	memset(visit, false, sizeof(visit));
}

void topology_sort() {
	vector<int> res;
	queue<int> q;
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (!inDegree[i]) q.push(i);
	}
	while (!q.empty()) {
		if (q.size() > 1) {
			flag = true;
			break;
		}
		int x = q.front();
		q.pop();
		res.push_back(x);
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (visit[x][y]) continue;
			inDegree[y]--;
			if (!inDegree[y]) q.push(y);
		}
	}
	if (flag) {
		cout << "?\n";
	}
	else if (res.size() != n) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			inDegree[arr[i]] = i;
			order[arr[i]] = i;
		}
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				v[arr[i]].push_back(arr[j]);
			}
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			if (order[x] < order[y]) {
				visit[x][y] = true;
				inDegree[x]++;
				inDegree[y]--;
				v[y].push_back(x);
			}
			else {
				visit[y][x] = true;
				inDegree[x]--;
				inDegree[y]++;
				v[x].push_back(y);
			}
		}
		topology_sort();
	}

	return 0;
}