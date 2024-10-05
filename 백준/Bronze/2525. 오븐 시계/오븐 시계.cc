#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x, y, t;
	cin >> x >> y >> t;
	x += (t + y) / 60;
	if (x >= 24) x -= 24;
	y = (y + t) % 60;
	cout << x << ' ' << y << '\n';
	return 0;
}