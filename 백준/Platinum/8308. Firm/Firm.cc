#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s;

class Q {
public:
	char c;
	int x, y;
};

class node {
public:
	int s, e, degree;
};

vector<Q> queries;
vector<int> edge[100001];
node info[100001];

int last_sorted_size[100001 * 4];

vector<int> seg[100001 * 4];

void dfs(int x, int d) {
	static int i = 0;
	info[x].degree = d;
	info[x].s = i++;
	for (int y : edge[x]) {
		dfs(y, d + 1);
	}
	info[x].e = i - 1;
}

void update(int x, int s, int e, int idx) {
	if (info[idx].s < s || e < info[idx].s) return;
	seg[x].push_back(info[idx].degree);	
	if (s == e) {		
		return;
	}
	int mid = s + (e - s) / 2;
	update(x * 2, s, mid, idx);
	update(x * 2 + 1, mid + 1, e, idx);
}

void ensure_sorted(int x) {
	if (last_sorted_size[x] < seg[x].size()) {
		// 새로운 원소들만 정렬 후 병합
		sort(seg[x].begin() + last_sorted_size[x], seg[x].end());
		inplace_merge(seg[x].begin(),
			seg[x].begin() + last_sorted_size[x],
			seg[x].end());
		last_sorted_size[x] = seg[x].size();
	}
}

int query(int x, int s, int e, int l, int r, int v) {
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		ensure_sorted(x);
		return upper_bound(seg[x].begin(), seg[x].end(), v)
			- lower_bound(seg[x].begin(), seg[x].end(), v);
	}
	int mid = s + (e - s) / 2;
	return query(x * 2, s, mid, l, r, v) + query(x * 2 + 1, mid + 1, e, l, r, v);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ch;
		int x, y;
		cin >> ch >> x >> y;
		if (ch == 'Z') {
			edge[y].push_back(x);
			s++;
		}
		queries.push_back({ ch, x, y });
	}
	dfs(1, 1);
	update(1, 0, s, 1);
	for (Q cur : queries) {
		if (cur.c == 'Z') {
			update(1, 0, s, cur.x);
		}
		else {
			int ret = query(1, 0, s, info[cur.x].s, info[cur.x].e, cur.y + info[cur.x].degree + 1);
			cout << ret << '\n';
		}
	}
	return 0;
}