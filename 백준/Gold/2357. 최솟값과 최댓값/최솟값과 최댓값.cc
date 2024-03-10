#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100005];
int min_seg[100005 * 4];
int max_seg[100005 * 4];

void init(int node, int start, int end) {
	if (start == end) {
		min_seg[node] = arr[start];
		max_seg[node] = arr[start];
		return;
	}
	int mid = start + (end - start) / 2;
	init(2 * node, start, mid);
	init(2 * node + 1, mid + 1, end);
	min_seg[node] = min(min_seg[2 * node], min_seg[2 * node + 1]);
	max_seg[node] = max(max_seg[2 * node], max_seg[2 * node + 1]);
}

int find_min(int node, int start, int end, int x, int y) {
	if (y < start || x > end) return 10000000000;
	if (x <= start && y >= end) return min_seg[node];
	int mid = start + (end - start) / 2;
	return min(find_min(2 * node, start, mid, x, y), find_min(2 * node + 1, mid + 1, end, x, y));
}

int find_max(int node, int start, int end, int x, int y) {
	if (y < start || x > end) return 0;
	if (x <= start && y >= end) return max_seg[node];
	int mid = start + (end - start) / 2;
	return max(find_max(2 * node, start, mid, x, y), find_max(2 * node + 1, mid + 1, end, x, y));
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, x, y;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		cout << find_min(1, 0, n - 1, x - 1, y - 1) << ' ' << find_max(1, 0, n - 1, x - 1, y - 1) << '\n';
	}
	return 0;
}