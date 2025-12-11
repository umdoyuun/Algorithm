#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int coord[502][502];
int dp[502][502];

class node {
public:
	int x, y, val;
	bool operator < (const node& other) const {
		return val < other.val;
	}
};

vector<node> v;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> coord[i][j];
			v.push_back({ i, j, coord[i][j] });
		}
	}
	sort(v.begin(), v.end());
	int res = 0;
	for (node cur : v) {
		dp[cur.x][cur.y] = 1;
		for (int i = 0; i < 4; i++) {
			int tx = cur.x + dx[i];
			int ty = cur.y + dy[i];
			if (coord[cur.x][cur.y] > coord[tx][ty]) {
				dp[cur.x][cur.y] = max(dp[cur.x][cur.y], dp[tx][ty] + 1);
			}
		}
		res = max(res, dp[cur.x][cur.y]);
	}
	cout << res;
	return 0;
}