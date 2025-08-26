#include <iostream>
using namespace std;

int n;
int x[51], y[51];
int arr[51];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (x[i] < x[j] && y[i] < y[j]) {
				arr[i]++;
			}
			else if (x[j] < x[i] && y[j] < y[i]) {
				arr[j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] + 1 << ' ';
	}
	return 0;
}