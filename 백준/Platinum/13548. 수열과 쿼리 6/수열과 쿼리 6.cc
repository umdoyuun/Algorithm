#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, q, sqn, s, e, mx;
int arr[100001];
int check[100001];
int res[100001];
int cnt[100001];
struct Q{
	int idx, s, e;
};

Q query[100001];

bool cmp(Q a, Q b) {
	if (a.s / sqn != b.s / sqn) return a.s < b.s;
	return a.e < b.e;
}

void sd(int idx) {
	for (int i = s - 1; i >= query[idx].s; i--) {
		check[cnt[arr[i]]]--;
		cnt[arr[i]]++;
		check[cnt[arr[i]]]++;
		mx = max(mx, cnt[arr[i]]);
	}
}

void su(int idx) {
	for (int i = s; i < query[idx].s; i++) {
		check[cnt[arr[i]]]--;
		if (mx == cnt[arr[i]] && check[cnt[arr[i]]] == 0) mx--;
		cnt[arr[i]]--;
		check[cnt[arr[i]]]++;
	}
}

void ed(int idx) {
	for (int i = e; i > query[idx].e; i--) {
		check[cnt[arr[i]]]--;
		if(mx == cnt[arr[i]] && check[cnt[arr[i]]] == 0) mx--;
		cnt[arr[i]]--;
		check[cnt[arr[i]]]++;
	}
}

void eu(int idx) {
	for (int i = e + 1; i <= query[idx].e; i++) {
		check[cnt[arr[i]]]--;
		cnt[arr[i]]++;
		check[cnt[arr[i]]]++;
		mx = max(mx, cnt[arr[i]]);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	sqn = sqrt(n);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> q;
	for (int i = 1; i <= q; i++) {
		int s, e;
		cin >> s >> e;
		query[i] = { i, s, e };
	}
	sort(query + 1, query + 1 + q, cmp);
	check[0] = query[1].e - query[1].s + 1;
	for (int i = query[1].s; i <= query[1].e; i++) {
		check[cnt[arr[i]]]--;
		cnt[arr[i]]++;
		check[cnt[arr[i]]]++;
		mx = max(mx, cnt[arr[i]]);
	}
	res[query[1].idx] = mx;
	s = query[1].s, e = query[1].e;
	for (int i = 2; i <= q; i++) {
		if (s > query[i].s) sd(i);
		if (s < query[i].s) su(i);
		if (e < query[i].e) eu(i);
		if (e > query[i].e) ed(i);
		s = query[i].s;
		e = query[i].e;
		res[query[i].idx] = mx;
	}
	for (int i = 1; i <= q; i++) {
		cout << res[i] << '\n';
	}
	return 0;
}