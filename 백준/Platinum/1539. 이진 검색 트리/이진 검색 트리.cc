#include <iostream>
#include <set>
#include <map>
using namespace std;

int n, root;
long long res;
//set<int> s;
map<int, pair<int, int>> m;
int dat[300001];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> root;
	m[root] = { -1, -1 };
	dat[root] = 1;
	res = 1;
	for (int i = 0; i < n - 1; i++) {
		int x;
		cin >> x;

		auto iter = m.lower_bound(x);
		if (iter == m.end()) {
			iter--;
			m[iter->first].second = x;
			dat[x] = dat[iter->first] + 1;
			res += dat[x];
		}
		else if (iter == m.begin()) {
			m[iter->first].first = x;
			dat[x] = dat[iter->first] + 1;
			res += dat[x];
		}
		else {
			if (m[iter->first].first == -1) {
				m[iter->first].first = x;
				dat[x] = dat[iter->first] + 1;
				res += dat[x];
			}
			else {
				iter--;
				m[iter->first].second = x;
				dat[x] = dat[iter->first] + 1;
				res += dat[x];
			}
		}
		m[x] = { -1, -1 };
	}
	cout << res << '\n';
	return 0;
}
