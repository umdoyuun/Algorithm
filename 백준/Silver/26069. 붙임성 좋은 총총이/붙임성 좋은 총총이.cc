#include <iostream>
#include <set>
using namespace std;

set<string> s;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string a, b;
	s.insert("ChongChong");
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (s.count(a) || s.count(b)) {
			s.insert(a);
			s.insert(b);
		}
	}
	int res = s.size();
	cout << res;
	return 0;
}