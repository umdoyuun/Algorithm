#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;
vector<int> row;
vector<int> col;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k;
	row.push_back(0);
	row.push_back(m);
	col.push_back(0);
	col.push_back(n);
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		if (x) {
			col.push_back(y);
		}
		else {
			row.push_back(y);
		}
	}
	sort(row.begin(), row.end());
	sort(col.begin(), col.end());
	int mx_r = 0, mx_c = 0;
	for (int i = 1; i < col.size(); i++) {		
		mx_c = max(mx_c, col[i] - col[i - 1]);
	}
	for (int i = 1; i < row.size(); i++) {
		mx_r = max(mx_r, row[i] - row[i - 1]);
	}
	cout << mx_c * mx_r << '\n';
	return 0;
}