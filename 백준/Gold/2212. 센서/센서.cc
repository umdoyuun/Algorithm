#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k;
long long res;
int arr[10001], arr2[10001];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++) {
		arr2[i] = arr[i + 1] - arr[i];
	}
	sort(arr2, arr2 + n, greater<>());
	for (int i = k - 1; i < n; i++) {
		res += arr2[i];
	}
	cout << res;
	return 0;
}