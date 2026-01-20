#include <iostream>
#include <algorithm>
using namespace std;

int n, tar;
int arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> tar;
	sort(arr, arr + n);
	int s = 0, e = n - 1, cnt = 0;
	while (s < e) {
		if (arr[s] + arr[e] == tar) cnt++;
		if (arr[s] + arr[e] < tar) s++;
		else e--;
	}
	cout << cnt;
	return 0;
}