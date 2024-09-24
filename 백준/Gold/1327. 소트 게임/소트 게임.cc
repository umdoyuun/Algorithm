#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

int n, k;
string arr, tar;
unordered_map<string, int> um;

int bfs() {
	queue<pair<string, int>> q;
	q.push({arr, 0});
	um[arr] = 1;
	while (!q.empty()) {
		string s = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (s == tar) return cnt;
		for (int i = 0; i <= n - k; i++) {
			string x = s.substr(i, k);
			string tmp = s.substr(0, i);
			for (int j = 0; j < k; j++) {
				tmp += x[k - 1 - j];
			}
			if(i+k < n)
				tmp += s.substr(i + k);
			if (um[tmp]) continue;
			q.push({ tmp, cnt + 1 });
			um[tmp] = 1;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		arr += c;
		tar += c;
	}
	sort(tar.begin(), tar.end());
	cout << bfs();
	return 0;
}