#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int inDegree[100001];
vector<int> v[100001];

void topology_sort() {
	priority_queue<int, vector<int>, greater<>> pq;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int x = pq.top();
		pq.pop();
		cout << x << ' ';
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (!(--inDegree[y])) {
				pq.push(y);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int  x, y;
		cin >> x >> y;
		inDegree[y]++;
		v[x].push_back(y);
	}
	topology_sort();
	return 0;
}