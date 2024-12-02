#include <iostream>
using namespace std;

int n, s, res;
int arr[100001];
bool visit[100001];

void dfs(int x) {
	if (visit[x]) return;
	res++;
	visit[x] = true;
	if (x - arr[x] > 0) dfs(x - arr[x]);
	if (x + arr[x] <= n) dfs(x + arr[x]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> s;
	dfs(s);
	cout << res << '\n';
	return 0;
}