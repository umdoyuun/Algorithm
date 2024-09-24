#include <iostream>
#include <set>
#include <map>
using namespace std;

int n, root;
long long res;
set<int> s;
map<int, pair<int, int>> m;
int dat[300001];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	cin >> root;
	cout << res << '\n';
	s.insert(root);
	for (int i = 0; i < n - 1; i++) {
		int x;
		cin >> x;
		
		auto iter = s.lower_bound(x);
		if (iter == s.end()) {
			iter--;
			m[*iter].second = x;
			dat[x] = dat[*iter] + 1;
			res += dat[x];
		}
		else if (iter == s.begin()) {
			m[*iter].first = x;
			dat[x] = dat[*iter] + 1;
			res += dat[x];
		}
		else {
			if (m[*iter].first == 0) {
				m[*iter].first = x;
				dat[x] = dat[*iter] + 1;
				res += dat[x];
			}
			else {
				iter--;
				m[*iter].second = x;
				dat[x] = dat[*iter] + 1;
				res += dat[x];
			}
		}
		s.insert(x);
		cout << res << '\n';
	}
	return 0;
}
