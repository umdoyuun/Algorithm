#include <iostream>
using namespace std;

int dp[101][101][101];

int func(int x, int y, int z) {
	if (dp[x + 50][y + 50][z + 50]) return dp[x + 50][y + 50][z + 50];
	if (x <= 0 || y <= 0 || z <= 0) return dp[x + 50][y + 50][z + 50] = 1;
	else if (x > 20 || y > 20 || z > 20) return dp[x + 50][y + 50][z + 50] = func(20, 20, 20);
	else if (x < y && y < z)return dp[x + 50][y + 50][z + 50] = func(x, y, z - 1) + func(x, y - 1, z - 1) - func(x, y - 1, z);
	else return dp[x + 50][y + 50][z + 50] = func(x - 1, y, z) + func(x - 1, y - 1, z) + func(x - 1, y, z - 1) - func(x - 1, y - 1, z - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x, y, z;
	while (1) {
		cin >> x >> y >> z;
		if (x == -1 && y == -1 && z == -1) break;
		cout << "w(" << x << ", " << y << ", " << z << ") = ";
		cout << func(x, y, z) << '\n';
	}
	return 0;
}