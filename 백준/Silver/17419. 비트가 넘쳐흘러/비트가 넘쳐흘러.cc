#include <iostream>
using namespace std;

int n;

void print(int x) {
	for (int i = n; i > 0; i--) {
		cout << ((x >> i) & 1);
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	int x = 0, res = 0;
	for (int i = 0; i < n; i++) {
		char y;
		cin >> y;
		if (y == '1')res++;
		//x = x << 1;
	}
	/*while (x) {
		cout << x << ' ';
		x = x - (x & ((~x) + 1));
		res++;
		print(x);
	}*/
	cout << res;
	return 0;
}