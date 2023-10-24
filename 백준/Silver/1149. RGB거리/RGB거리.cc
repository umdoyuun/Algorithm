#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int rgb[3];
int cost[1001][3];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, result;
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> rgb[0] >> rgb[1] >> rgb[2];
		cost[i][0] = min(cost[i - 1][1] + rgb[0], cost[i - 1][2] + rgb[0]);
		cost[i][1] = min(cost[i - 1][0] + rgb[1], cost[i - 1][2] + rgb[1]);
		cost[i][2] = min(cost[i - 1][0] + rgb[2], cost[i - 1][1] + rgb[2]);
	}
	result = min(cost[n][0], cost[n][1]);
	result = min(cost[n][2], result);
	
	cout << result;
	return 0;
}