#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, q;

struct node {
	int s, e, level, num;
};
//struct connect {
//	int s, e, level, e_cnt;
//};
vector<node> v;
//vector<connect> conn;
node pool[100001];
int connect[100001];
int connect_cnt;

bool cmp(node a, node b) {
	if (a.s == b.s) {
		return a.e < b.e;
	}
	else return a.s < b.s;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for (register int i = 0; i < n; i++) {
		int s, e, level;
		cin >> s >> e >> level;
		v.push_back({ s, e, level, i + 1 });
		pool[i + 1] = { s, e, level, i + 1};
	}
	sort(v.begin(), v.end(), cmp);
	int s = 0, e = 0, level = 0, e_cnt = 0;
	for (register int i = 0; i < n; i++) {
		node x = v[i];
		if (i == 0) {
			s = x.s;
			e = x.e;
			level = x.level;
			e_cnt = 1;
			connect[x.num] = connect_cnt;
			continue;
		}
		if (x.s < e) {
			if (e == x.e) {
				e_cnt++;

			}
			else if(x.e > e){
				e = x.e;
				e_cnt = 1;
			}
		}
		else if (x.s == e) {
			if (e_cnt > 1 || x.level != level) {
				e = x.e;
				level = x.level;
				e_cnt = 1;
			}
			else if (i != n - 1 && v[i + 1].s == e) {
				e = x.e;
				level = x.level;
				e_cnt = 1;
			}
			else {
				//conn.push_back({ s, e, level, e_cnt });
				connect_cnt++;
				s = x.s;
				e = x.e;
				level = x.level;
				e_cnt = 1;
			}
		}
		else {
			//conn.push_back({ s, e, level, e_cnt });
			connect_cnt++;
			s = x.s;
			e = x.e;
			level = x.level;
			e_cnt = 1;
		}
		connect[x.num] = connect_cnt;
	}
	for (register int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		if (connect[x] != connect[y]) cout << "0\n";
		else cout << "1\n";
	}

	/*for (register int i = 0; i < n; i++) {
		cout << connect[i + 1] << ' ';
	}*/
	return 0;
}