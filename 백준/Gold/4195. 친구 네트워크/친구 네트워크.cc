#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int n, cnt;
unordered_map<string, int> um;
int par[200001];
int f_cnt[200001];

void init() {
	um.clear();
	cnt = 0;
}

int getParent(int x) {
	if (x == par[x]) return x;
	else return par[x] = getParent(par[x]);
}

int unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x == y) return f_cnt[x];
	par[y] = x;
	f_cnt[x] += f_cnt[y];
	f_cnt[y] = 0;
	return f_cnt[x];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		init();
		cin >> n;
		for (int i = 0; i < n; i++) {
			string str1, str2;
			cin >> str1 >> str2;
			if (um.find(str1) == um.end()) {
				um.insert({ str1, ++cnt });
				par[cnt] = cnt;
				f_cnt[cnt] = 1;
			}
			if (um.find(str2) == um.end()) {
				um.insert({ str2, ++cnt });
				par[cnt] = cnt;
				f_cnt[cnt] = 1;
			}
			cout << unionParent(um[str1], um[str2]) << '\n';
		}
	}
	return 0;
}