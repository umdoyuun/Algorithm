#include <iostream>
#include <vector>
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, k;
	int inDegree[100001] = { 0, };
	int is_build[100001] = { 0, };
	cin >> n >> m >> k;
	vector<vector<int>> v(n + 1, vector<int>());
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		inDegree[y]++;
		v[x].push_back(y);
	}

	bool res = true;
	for (int i = 0; i < k; i++) {
		int cmd, x;
		cin >> cmd >> x;
		if (cmd == 1) {
			if (inDegree[x]) {
				res = false;
				break;
			}
			
			if (!is_build[x]) {
				for (int i = 0; i < v[x].size(); i++) {
					int y = v[x][i];
					inDegree[y]--;
				}
			}
			is_build[x]++;
		}
		else {
			if (is_build[x] <= 0) {
				res = false;
				break;
			}
			is_build[x]--;
			if (is_build[x] == 0) {
				for (int i = 0; i < v[x].size(); i++) {
					int y = v[x][i];
					inDegree[y]++;
				}
			}
		}
	}
	if (res) cout << "King-God-Emperor\n";
	else cout << "Lier!\n";
	return 0;
}