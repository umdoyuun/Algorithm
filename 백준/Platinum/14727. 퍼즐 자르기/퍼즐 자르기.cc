#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e9;

int n;
int arr[100001];
long long res;

class node {
public:
	int mn, x;
}seg[100001 * 4];

node init(int x, int s, int e) {
	if (s == e) return seg[x] = { arr[s], s };
	int mid = s + (e - s) / 2;
	node left = init(x * 2, s, mid);
	node right = init(x * 2 + 1, mid + 1, e);
	if (left.mn > right.mn) return seg[x] = right;
	else return seg[x] = left;
}

node query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return { MAX, -1 };
	if (l <= s && e <= r) return seg[x];
	int mid = s + (e - s) / 2;
	node left = query(x * 2, s, mid, l, r);
	node right = query(x * 2 + 1, mid + 1, e, l, r);
	if (left.mn > right.mn) return right;
	else return left;
}

void find_min(int s, int e) {
	node ret = query(1, 0, n - 1, s, e);
	long long tmp = (long long)ret.mn * (long long)(e - s + 1);
	res = max(res, tmp);
	if(ret.x > s)
		find_min(s, ret.x - 1);
	if(ret.x < e)
		find_min(ret.x + 1, e);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	find_min(0, n - 1);
	cout << res << '\n';
	return 0;
}