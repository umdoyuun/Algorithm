#include <iostream>
#include <algorithm>
using namespace std;

int arr[20000001];
int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[x + 10000000]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		cout << arr[x + 10000000] << ' ';
	}
	return 0;
}