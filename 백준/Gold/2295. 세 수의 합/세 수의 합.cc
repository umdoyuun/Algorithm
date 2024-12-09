#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			v.push_back(arr[i] + arr[j]);
		}
	}
	sort(v.begin(), v.end());
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			int x = arr[i] - arr[j];
			int y = *lower_bound(v.begin(), v.end(), x);
			if (y == x) {
				cout << arr[i] << '\n';
				return 0;
			}
		}
	}
	return 0;
}