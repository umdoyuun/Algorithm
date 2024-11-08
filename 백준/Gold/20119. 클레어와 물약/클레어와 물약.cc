#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;


int n, m, l;
vector<int> inDegree[200001];
int input[200001];
vector<pair<int, int>> v[200001];
int cnt[200001];
bool visit[200001];
queue<int> q;

void topology_sort() {
	vector<int> res;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		res.push_back(x);
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i].first;
			int idx = v[x][i].second;
			if (--inDegree[y][idx] == 0 && !visit[y]) {
				q.push(y);
				visit[y] = true;
			}
		}
	}

	sort(res.begin(), res.end());
	cout << res.size() << '\n';
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int k, x;
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> input[j];
		}
		cin >> x;
		
		inDegree[x].push_back(k);
		for (int j = 0; j < k; j++) {
			v[input[j]].push_back({x, cnt[x]});
		}
		cnt[x]++;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		int x;
		cin >> x;
		q.push(x);
		visit[x] = true;
	}
	topology_sort();
	return 0;
}