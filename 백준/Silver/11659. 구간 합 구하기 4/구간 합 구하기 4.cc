#include <iostream>
using namespace std;

int n, m;
int arr[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		arr[i] = arr[i - 1] + x;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		cout << arr[y] - arr[x - 1] << '\n';
	}
	return 0;
}