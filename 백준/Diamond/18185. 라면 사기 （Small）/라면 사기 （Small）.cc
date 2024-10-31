#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, pre = 0, prepre = 0;
	long long res = 0;
	int arr[10001];
	cin >> n;
	cin >> arr[0] >> arr[1];
	res += (arr[0] + arr[1]) * 3;
	for (int i = 2; i < n; i++) {
		cin >> arr[i];
		res += arr[i] * 3;
		
		if (arr[i] < arr[i - 1]) {
			int tmp = min(arr[i - 2], arr[i - 1] - arr[i]);
			res -= tmp;
			arr[i - 1] -= tmp;
			arr[i - 2] -= tmp;
		}
		int tmp = min({ arr[i], arr[i - 1], arr[i - 2] });
		res -= tmp * 2;
		for (int j = i - 2; j <= i; j++) {
			arr[j] -= tmp;
		}
	}
	for (int i = 1; i < n; i++) {
		int tmp = min({ arr[i], arr[i - 1] });
		res -= tmp;
		for (int j = i - 1; j <= i; j++) {
			arr[j] -= tmp;
		}
	}
	cout << res << '\n';
	return 0;
}