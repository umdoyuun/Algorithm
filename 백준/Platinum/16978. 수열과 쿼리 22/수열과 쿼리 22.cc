#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long arr[100001];
long long seg[100001 * 4];

struct q1 {
	int x;
	long long v;
};
struct q2 {
	int x, l, r, idx;
};
vector<q1> v1;
vector<q2> v2;
int q_cnt;
long long res[100001];

bool cmp(q2 a, q2 b) {
	return a.x < b.x;
}

long long init(int x, int s, int e) {
	if (s == e) {
		return seg[x] = arr[s];
	}
	int mid = s + (e - s) / 2;
	return seg[x] = init(x * 2, s, mid) + init(x * 2 + 1, mid + 1, e);
}

long long update(int x, int s, int e, int idx, long long diff){
	if (idx < s || idx > e) return seg[x];
	if (s == e) {
		return seg[x] = diff;
	}
	int mid = s + (e - s) / 2;
	return seg[x] = update(x * 2, s, mid, idx, diff) + update(x * 2 + 1, mid + 1, e, idx, diff);
}

long long query(int x, int s, int e, int l, int r) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg[x];
	}
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r) + query(x * 2 + 1, mid + 1, e, l, r);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int cmd;
		cin >> cmd;
		if (cmd == 1) {
			int x;
			long long v;
			cin >> x >> v;
			v1.push_back({ x - 1, v });
		}
		else {
			int k, l, r;
			cin >> k >> l >> r;
			v2.push_back({ k, l - 1, r - 1, q_cnt++ });
		}
	}
	sort(v2.begin(), v2.end(), cmp);
	int q1_idx = 0;
	for (int i = 0; i < v2.size(); i++) {
		while (v2[i].x > q1_idx) {
			update(1, 0, n - 1, v1[q1_idx].x, v1[q1_idx].v);
			q1_idx++;
		}
		
		res[v2[i].idx] = query(1, 0, n - 1, v2[i].l, v2[i].r);
	}
	for (int i = 0; i < q_cnt; i++) {
		cout << res[i] << '\n';
	}
	return 0;
}