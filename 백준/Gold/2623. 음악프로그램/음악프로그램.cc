#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, inDegree[1001];
vector<int> v[1001];
int result[1001];

bool topologySort() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) q.push(i);
	}
	for (int i = 1; i <= n; i++) {
		if (q.empty()) return false;
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int j = 0; j < v[x].size(); j++) {
			int y = v[x][j];
			inDegree[y]--;
			if (inDegree[y] == 0) {
				q.push(y);
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k, x, tmp;
		cin >> k;
		cin >> x;
		tmp = x;
		for (int j = 1; j < k; j++) {
			cin >> x;
			v[tmp].push_back(x);
			inDegree[x]++;
			tmp = x;
		}
	}
	if (topologySort()) {
		for (int i = 1; i <= n; i++)
			cout << result[i] << '\n';
	}
	else
		cout << 0;
	return 0;
}