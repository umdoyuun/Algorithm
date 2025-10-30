#include <iostream>
#include <algorithm>
using namespace std;

struct flower {
	int sm, sd, em, ed;
};
flower f[100001];

bool cmp(flower a, flower b) {
	if (a.sm == b.sm) {
		if (a.sd == b.sd) {
			if (a.em == b.em) {
				return a.ed > b.ed;
			}
			return a.em > b.em;
		}
		return a.sd < b.sd;
	}
	return a.sm < b.sm;
}

int main() {
	int m = 3, d = 1, n, res = 0, x = 0, y = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		f[i] = { sm, sd, em, ed };
	}
	sort(f, f + n, cmp);
	
	for (int i = 0; i < n; i++) {
		if (m > 12) {
			break;
		}
		if (m < f[i].sm || (m == f[i].sm && d < f[i].sd)) {
			m = x;
			d = y;
			res++;
		}
		if (m > f[i].sm || (m == f[i].sm && d >= f[i].sd)) {
			if (x < f[i].em || (x == f[i].em && y <= f[i].ed)) {
				x = f[i].em;
				y = f[i].ed;
			}
		}
		
	}
	if (m < 12 && m < x) {
		res++;
		m = x;
		d = y;
	}
	if (m < 12) res = 0;
	cout << res << '\n';
	return 0;
}