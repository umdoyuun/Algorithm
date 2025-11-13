#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[500001];
int tmp[500001];

long long res;

void merge_sort(int s, int e) {
	if (s >= e) return;
	int mid = (s + e) / 2;
	merge_sort(s, mid);
	merge_sort(mid + 1, e);

	int i = s, j = mid + 1, k = s;
	while (i <= mid && j <= e) {
		if (arr[i] <= arr[j]) {
			tmp[k++] = arr[i++];
		}
		else {
			tmp[k++] = arr[j++];
			res += mid - i + 1;
		}
	}
	while (i <= mid) tmp[k++] = arr[i++];
	while (j <= e) tmp[k++] = arr[j++];

	for (int i = s; i <= e; i++) {
		arr[i] = tmp[i];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	merge_sort(0, n - 1);
	cout << res;
	return 0;
}