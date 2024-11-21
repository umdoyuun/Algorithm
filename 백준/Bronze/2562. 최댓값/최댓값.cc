#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int res = 0;
	int Max = 0;
	for (int i = 1; i < 10; i++) {
		int x;
		cin >> x;
		if (x > Max) {
			res = i;
			Max = x;
		}
	}
	cout << Max << '\n' << res << '\n';
	return 0;
}