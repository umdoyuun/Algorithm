#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

long long n, k;

long long find(long long x) {
	long long cnt = 0;
	for (long long i = 1; i <= n; i++) {
		cnt += min(n, x / i);
	}
	return cnt;
}

long long func() {
	long long start = 1, end = min(n * n, (long long)1000000000);
	while (start <= end) {
		long long mid = (start + end) / 2;
		long long cnt = find(mid);
		if (cnt >= k) end = mid - 1;
		else start = mid + 1;
	}
	return start;
}

int main() {
	cin >> n >> k;
	cout << func();
	return 0;
}