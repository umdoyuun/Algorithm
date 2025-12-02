#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int n, b, c;
int a[1000001];
long long result = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;
	result = n;
	for (int i = 0; i < n; i++) {
		a[i] -= b;
		if (a[i] <= 0) continue;
		result += a[i] / c;
		if (a[i] % c != 0)
			result++;
	}
	cout << result;
	return 0;
}