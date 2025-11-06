#include <iostream>
#include <algorithm>
using namespace std;

int n;


struct node {
	int x, y;
};

node arr[100001];

bool cmp(node a, node b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << arr[i].x << ' ' << arr[i].y << '\n';
	}
	return 0;
}