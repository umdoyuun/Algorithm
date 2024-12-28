#include <iostream>
using namespace std;

int cnt[10];

int main() {
	int n, x;
	cin >> n;
	cin >> x;
	n *= x;
	cin >> x;
	n *= x;
	while (n) {
		int a = n % 10;
		cnt[a]++;
		n /= 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << cnt[i] << '\n';
	}
	return 0;
}