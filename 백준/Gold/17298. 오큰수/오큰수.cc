#include <iostream>
#include <deque>
using namespace std;

int n;
deque<int> dq;
int arr[1000001];
int res[1000001];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int cnt = n - 1, max = 0;
	res[n - 1] = -1;
	max = arr[n - 1];
	dq.push_back(arr[n - 1]);
	for (int i = n - 2; i >= 0; i--) {
		if (arr[i] >= max) {
			res[i] = -1;
			max = arr[i];
			dq.clear();
			dq.push_front(arr[i]);
		}
		else {
			while (!dq.empty()) {
				if (dq.front() <= arr[i]) dq.pop_front();
				else break;
			}
			res[i] = dq.front();
			dq.push_front(arr[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << ' ';
	}
	return 0;
}