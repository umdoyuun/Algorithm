#include <iostream>
#include <algorithm>
using namespace std;

int x, y, res, total;

int main() {
	for (int i = 0; i < 4; i++) {
		cin >> x >> y;
		total += y - x;
		res = max(res, total);
	}
	cout << res;
	return 0;
}