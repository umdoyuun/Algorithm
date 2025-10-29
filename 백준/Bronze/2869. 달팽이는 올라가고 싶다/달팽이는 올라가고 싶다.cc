#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b, tar;
	cin >> a >> b >> tar;
	tar -= b;
	if (tar % (a - b)) {
		tar += (a - b);
	}
	int res = tar / (a - b);
	cout << res;
	return 0;
}