#include <iostream>
#include <algorithm>
using namespace std;

const int mx = 0x7fffffff;
int n, m, res, sz;
int graph[2001][2001];
int sum[2001][2];
long long total;

void snow_cleaning() {
	int flag = 0;
	int mn = mx;
	int idx = 0;
	int tmp_mx = 0;
	for (int i = 0; i < sz; i++) {
		if (!sum[i][0]) continue;
		tmp_mx = max(tmp_mx, sum[i][0]);
		if (mn > sum[i][0]) {
			mn = sum[i][0];
			idx = i;			
		}
	}
	for (int i = 0; i < sz; i++) {
		if (!sum[i][1]) continue;
		tmp_mx = max(tmp_mx, sum[i][1]);
		if (mn > sum[i][1]) {
			flag = 1;
			mn = sum[i][1];
			idx = i;			
		}
	}
	if (tmp_mx < res) {
		total = 0;
		return;
	}
	total -= mn;
	res = max(res, mn);
	
	if (flag) {
		for (int i = 0; i < sz; i++) {
			sum[i][0] -= graph[idx][i];
			graph[idx][i] = 0;
		}
	}
	else {
		for (int i = 0; i < sz; i++) {
			sum[i][1] -= graph[i][idx];
			graph[i][idx] = 0;
		}
	}
	sum[idx][flag] = 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	sz = max(n, m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> graph[i][j];
			total += graph[i][j];
			sum[j][0] += graph[i][j];
			sum[i][1] += graph[i][j];
		}
	}
	while (total) {
		snow_cleaning();
	}
	cout << res << '\n';
	return 0;
}