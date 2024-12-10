#include <iostream>
#include <map>
using namespace std;

int n, m;
string cmd;
int graph[1001][1001];

map<char, pair<int, int>> M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		graph[a + 500][b + 500] = 1;
	}
	int x = 500, y = 500;
	M['L'] = { 0, -1 };
	M['R'] = { 0, 1 };
	M['U'] = { 1, 0 };
	M['D'] = { -1, 0 };
	cin >> cmd;
	for (char c : cmd) {
		int dy = M[c].first;
		int dx = M[c].second;
		int nx = x + dx;
		int ny = y + dy;
		if (!graph[nx][ny]) {
			x = nx;
			y = ny;
		}
	}
	cout << x - 500 << ' ' << y - 500 << '\n';
	return 0;
}