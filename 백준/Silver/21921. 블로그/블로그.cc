#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, x;
int arr[250001];
long long result = 0;
int cnt = 1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> x;
	long long y = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i < x) {
			y += arr[i];
			result = y;
		}
		else {
			y = y - arr[i - x] + arr[i];
			if (result == y) cnt++;
			if (result < y) {
				result = y;
				cnt = 1;
			}
		}
	}
	if (result == 0) {
		cout << "SAD\n";
	}
	else {
		cout << result << '\n' << cnt << '\n';
	}
	return 0;
}