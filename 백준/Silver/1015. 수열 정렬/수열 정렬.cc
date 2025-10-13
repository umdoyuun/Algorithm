#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[j].second == i) {
				cout << j << ' ';
				break;
			}
		}
	}
	return 0;
}