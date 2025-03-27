#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;
	}
	sort(arr, arr + n);
	int res = 0, e = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].second >= e) {
			res++;
			e = arr[i].first;
		}
	}
	cout << res << '\n';
	return 0;
}