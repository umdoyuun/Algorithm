#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1000001][2];
vector<int> v[1000001];
bool visit[1000001];
int n;

void dfs(int x){
	visit[x] = true;
	dp[x][0] = 0;
	dp[x][1] = 1;
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (visit[y]) continue;
		dfs(y);
		dp[x][0] += dp[y][1];
		dp[x][1] += min(dp[y][0], dp[y][1]);
	}
	
}

int main()
{
	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	cout << min(dp[1][0], dp[1][1]);
	return 0;
}