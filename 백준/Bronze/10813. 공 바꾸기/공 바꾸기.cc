#include <iostream>
using namespace std;

int arr[101];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		int tmp = arr[x];
		arr[x] = arr[y];
		arr[y] = tmp;
	}
	for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
	return 0;
}