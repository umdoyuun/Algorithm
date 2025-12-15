#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <set>
using namespace std;

multiset<int> q;
int n, x;
char flag;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, tc;
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		q = multiset<int>();
		for (int i = 0; i < n; i++) {
			cin >> flag >> x;
			switch (flag) {
			case 'I':
				q.insert(x);
				break;
			case 'D':
				if (!q.empty()) {
					if (x == 1) {
						auto iter = q.end();
						iter--;
						q.erase(iter);
					}
					if (x == -1) 
						q.erase(q.begin());
				}
			}
		}
		if (q.empty())
			cout << "EMPTY" << '\n';
		else {
			auto iter = q.end();
			iter--;
			cout << *iter << ' ' << *q.begin() << '\n';
		}
	}
	return 0;
}