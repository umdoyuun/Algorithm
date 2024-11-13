#include <iostream>
using namespace std;

 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	int cnt[1001] = { 0, };
	long long res = 0;
	cin >> n >> m;
	int x, sum = 0;
	cnt[0] = 1;
	for (register int i = 0; i < n; i++) {
		cin >> x;
		sum = (sum + x) % m;
		cnt[sum]++;
	}
	for (register int i = 0; i < m; i++) {
		res += (long long)cnt[i] * (long long)(cnt[i] - 1) / 2;
	}
	cout << res;
	return 0;
}

//