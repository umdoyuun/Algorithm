#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
struct node {
	int x, y, cost;
};

vector<node> v;

int par[401];
int cnt[401], t_cnt, res;
bool visit[401];

bool cmp(node a, node b) {
	/*if (a.cost == b.cost) {
		if (a.x == a.y) return false;
		else return true;
	}*/
	return a.cost < b.cost;
}

int getPar(int x) {
	if (x == par[x]) return x;
	else return par[x] = getPar(par[x]);
}

bool unionPar(int x, int y) {
	x = getPar(x);
	y = getPar(y);
	if (visit[x] && visit[y]) return false;
	if (x == y) return false;
	if (!visit[x] && !visit[y]) {
		par[y] = x;
		//cnt[x] += cnt[y];
		//cnt[y] = 0;
	}
	else if (!visit[x]) {
		par[x] = y;
		cnt[y] += cnt[x];
		t_cnt += cnt[x];
		//cnt[x] = 0;
	}
	else {
		par[y] = x;
		cnt[x] += cnt[y];
		t_cnt += cnt[y];
		//cnt[y] = 0;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt[i] = 1;
		par[i] = i;
		v.push_back({ i, i, x });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			if (i != j) {
				v.push_back({ i, j, x });
			}
		}
	}
	//for (int i = 1; i <= n; i++) cout << par[i] << ' ';
	//cout << '\n';
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		//cout << t_cnt << '\n';
		if (t_cnt == n) break;
		int x = v[i].x;
		int y = v[i].y;
		if (x == y && !visit[getPar(x)]) {
			//cout << "b" << ' ' << x << ' ' << y << '\n';
			res += v[i].cost;
			visit[getPar(x)] = true;
			t_cnt += cnt[getPar(x)];
		}
		else {
			if (unionPar(x, y)) {
				//cout << x << ' ' << y << '\n';
				res += v[i].cost;
			}
		}
	}
	cout << res << '\n';
	return 0;
}