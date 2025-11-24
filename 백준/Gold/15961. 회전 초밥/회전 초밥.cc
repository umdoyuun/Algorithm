#include <iostream>
#include <algorithm>
using namespace std;

int n, d, k, c, res;
int arr[3003002];
int cnt[3001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < k; i++) {
		arr[n + i] = arr[i];
	}
	cnt[c] = 1;
	res = 1;
	for (int i = 0; i < k; i++) {
		if (!cnt[arr[i]]) res++;
		cnt[arr[i]]++;
	}
	int s = 0, e = k;
	int tmp = res;
	for (e; e < n + k; e++, s++) {
		if (!cnt[arr[e]]) tmp++;
		cnt[arr[e]]++;
		cnt[arr[s]]--;
		if (!cnt[arr[s]]) tmp--;
		res = max(tmp, res);
	}
	cout << res;
	return 0;
}