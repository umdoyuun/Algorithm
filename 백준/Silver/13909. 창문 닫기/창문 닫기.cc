#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i * i <= n; i++) {
		res++;
	}
	cout << res << '\n';
	return 0;
}