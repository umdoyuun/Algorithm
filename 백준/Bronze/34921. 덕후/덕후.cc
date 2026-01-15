#include <iostream>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	int res = 10 + 2 * (25 - x + y);
	if (res < 0) res = 0;
	cout << res;
	return 0;
}