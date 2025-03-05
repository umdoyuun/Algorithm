#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, res;
vector<int> v[2];
int arr[2001];

int binary_search(vector<int>& list, int s, int e, int x) {
	while (s < e) {
		int mid = s + (e - s) / 2;
		if (x > list[mid]) s = mid + 1;
		else e = mid;
	}
	return e;
}

int LIS(int x) {
	int ret[2] = { 0, };
	vector<int> list;
	list.push_back(-arr[x]);
	for (int i = x + 1; i < n; i++) {
		if (arr[i] > arr[x]) continue;
		if (-arr[i] > list.back()) {
			list.push_back(-arr[i]);
			ret[0] = list.size() - 1;
		}
		int pos = binary_search(list, 0, ret[0], -arr[i]);
		list[pos] = -arr[i];

	}
	list.clear();
	list.push_back(arr[x]);
	for (int i = x + 1; i < n; i++) {
		if (arr[i] < arr[x]) continue;
		if (arr[i] > list.back()) {
			list.push_back(arr[i]);
			ret[1] = list.size() - 1;
		}
		int pos = binary_search(list, 0, ret[1], arr[i]);
		list[pos] = arr[i];
	}
	return ret[0] + ret[1] + 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		res = max(res, LIS(i));
	}
	cout << res << '\n';
	return 0;
}