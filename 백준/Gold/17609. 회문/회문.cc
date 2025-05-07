#include <iostream>
#include <algorithm>
using namespace std;

int t;

int check(string str, int l, int r, int cnt) {
	if (cnt > 1) return 2;
	int ret = 0;
	while (l < r) {
		if (str[l] != str[r]) {
			return min(check(str, l + 1, r, cnt + 1), check(str, l, r - 1, cnt + 1));
		}
		l++;
		r--;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		int l = 0, r = str.size() - 1, cnt = 0;
		cout << check(str, l, r, cnt) << '\n';
	}
	return 0;
}