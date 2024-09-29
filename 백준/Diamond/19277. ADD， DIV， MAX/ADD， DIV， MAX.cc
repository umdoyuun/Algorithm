#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define INF 0x7fffffff


long long arr[200001];
struct node {
	long long mx, mn;
};
long long seg[200002 * 4][3];
long long lazy[200002 * 4][2]; // 0: sum 1: sqrt

void prop(long long no, long long s, long long e)
{
	if (!lazy[no][0] && lazy[no][1] == INF)
		return;

	if (lazy[no][1] == INF)
	{
		seg[no][0] += lazy[no][0];
		seg[no][1] += lazy[no][0];
		seg[no][2] += (e - s + 1) * lazy[no][0];

		if (s != e)
		{
			lazy[no * 2][0] += lazy[no][0];
			lazy[no * 2 + 1][0] += lazy[no][0];
		}
	}

	else
	{
		seg[no][0] = seg[no][1] = lazy[no][1] + lazy[no][0];
		seg[no][2] = (e - s + 1) * (lazy[no][1] + lazy[no][0]);

		if (s != e)
		{
			lazy[no * 2][0] = lazy[no * 2 + 1][0] = lazy[no][0];
			lazy[no * 2][1] = lazy[no * 2 + 1][1] = lazy[no][1];
		}
	}

	lazy[no][0] = 0;
	lazy[no][1] = INF;
}

void update1(long long no, long long s, long long e, long long l, long long r, long long v)
{
	prop(no, s, e);

	if (e < l || r < s)
		return;

	if (l <= s && e <= r)
	{
		lazy[no][0] = v;
		prop(no, s, e);

		return;
	}

	update1(no * 2, s, (s + e) / 2, l, r, v);
	update1(no * 2 + 1, (s + e) / 2 + 1, e, l, r, v);

	seg[no][0] = max(seg[no * 2][0], seg[no * 2 + 1][0]);
	seg[no][1] = min(seg[no * 2][1], seg[no * 2 + 1][1]);
	seg[no][2] = seg[no * 2][2] + seg[no * 2 + 1][2];
}

void update2(long long no, long long s, long long e, long long l, long long r, long long v)
{
	prop(no, s, e);

	if (e < l || r < s)
		return;

	if (l <= s && e <= r)
	{
		if (floor((long double)seg[no][0] / (long double)v) == floor((long double)seg[no][1] / (long double)v))
		{
			lazy[no][1] = floor((long double)seg[no][0] / (long double)v);
			prop(no, s, e);

			return;
		}

		if (seg[no][1] + 1 == seg[no][0])
		{
			lazy[no][0] = floor((long double)seg[no][1] / (long double)v) - seg[no][1];
			prop(no, s, e);

			return;
		}
	}

	update2(no * 2, s, (s + e) / 2, l, r, v);
	update2(no * 2 + 1, (s + e) / 2 + 1, e, l, r, v);

	seg[no][0] = max(seg[no * 2][0], seg[no * 2 + 1][0]);
	seg[no][1] = min(seg[no * 2][1], seg[no * 2 + 1][1]);
	seg[no][2] = seg[no * 2][2] + seg[no * 2 + 1][2];
}

long long query1(long long no, long long s, long long e, long long l, long long r)
{
	prop(no, s, e);

	if (e < l || r < s)
		return 0;

	if (l <= s && e <= r)
		return seg[no][0];

	return max(query1(no * 2, s, (s + e) / 2, l, r), query1(no * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 200002 * 4; i++) {
		lazy[i][1] = INF;
	}
	for (register int i = 0; i < n; i++) {
		cin >> arr[i];
		update1(1, 0, n - 1, i, i, arr[i]);
	}
	for (register int i = 0; i < m; i++) {
		int cmd, l, r;
		long long x;
		cin >> cmd >> l >> r >> x;
		if (cmd == 0) {
			update1(1, 0, n - 1, l, r, x);
		}
		else if (cmd == 1) {
			update2(1, 0, n - 1, l, r, x);
		}
		else if (cmd == 2) {
			long long res = query1(1, 0, n - 1, l, r);
			cout << res << '\n';
		}
	}
	return 0;
}