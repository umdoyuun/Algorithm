#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int cnt = 0;
int result = 0;


void func(int n, int x, int y) {
	if (x == r && y == c) {
		result = cnt;
		return;
	}
	if (x + n > r && y + n > c && x <= r && y <= c) {
		func(n / 2, x, y);
		func(n / 2, x, y + n / 2);
		func(n / 2, x + n / 2, y);
		func(n / 2, x + n / 2, y + n / 2);
	}
	else {
		cnt += n * n;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> r >> c;
	func(pow(2, N), 0, 0);
	cout << result;
	return 0;
}