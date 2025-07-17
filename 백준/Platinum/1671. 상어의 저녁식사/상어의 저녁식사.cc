#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int n, res;

struct shark {
	int a, b, c;
}sharks[51];

bool visit[51];
int d[51];
vector<int> v[51];

void make_edge() {
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (sharks[i].a <= sharks[j].a && sharks[i].b <= sharks[j].b && sharks[i].c <= sharks[j].c) {
				v[j].push_back(i);
			}
			else if (sharks[j].a <= sharks[i].a && sharks[j].b <= sharks[i].b && sharks[j].c <= sharks[i].c) {
				v[i].push_back(j);
			}
		}
	}
}

bool dfs(int x) {
	if (visit[x]) return false;
	visit[x] = true;

	for (auto y : v[x]) {
		if (!d[y] || dfs(d[y])) {
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
	cin >> n;
	vector<pair<int, int>> arr;
	for (int i = 1; i <= n; i++) {
		cin >> sharks[i].a >> sharks[i].b >> sharks[i].c;
	}
	make_edge();
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		if (dfs(i)) res++;
		memset(visit, false, sizeof(visit));
		if (dfs(i)) res++;
	}
	cout << n - res << '\n';
	return 0;
}