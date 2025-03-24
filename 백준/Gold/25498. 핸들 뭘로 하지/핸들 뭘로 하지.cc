#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, Cnt;
string str;
vector<int> v[500001];

bool cmp(int x, int y) {
	return str[x] > str[y];
}

char dat[500001];
int idx[500001];
void dfs(int x, int pre, int cnt) {
	if (idx[cnt - 1] != pre) return;
	if (str[x] < dat[cnt]) return;
	if (str[x] > dat[cnt]) {
		for (int i = cnt + 1; i <= Cnt;i++) {
			dat[i] = '\0';
		}
        Cnt = cnt;
	}
	Cnt = max(cnt, Cnt);
	dat[cnt] = str[x];
	idx[cnt] = x;
	char next = '\0';
	sort(v[x].begin(), v[x].end(), cmp);
	for (auto y : v[x]) {
		if (y == pre) continue;
		if (next == '\0') {
			next = str[y];
		}
		else if (next != str[y]) break;
		dfs(y, x, cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> str;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--;y--;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(0, 0, 1);
	for (int i = 1; i <= Cnt; i++) {
		cout << dat[i];
	}
	return 0;
}
