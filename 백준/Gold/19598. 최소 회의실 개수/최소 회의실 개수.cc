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
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n);
	priority_queue<int> pq;
	int res = 0;
	for (int i = 0; i < n;i++) {
		while (!pq.empty() && -pq.top() <= arr[i].first) {
			pq.pop();
		}

		pq.push(-arr[i].second);
		res = max(res, int(pq.size()));
	}
	cout << res << '\n';
	return 0;
}