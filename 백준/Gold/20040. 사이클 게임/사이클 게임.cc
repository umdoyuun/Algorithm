#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int parent[500000];


int getParent(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = getParent(parent[x]);
}

void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	parent[x] = y;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		if (getParent(x) == getParent(y)) {
			cout << i;
			flag = true;
			break;
		}
		unionParent(x, y);
	}
	if(!flag)
		cout << 0;
	return 0;
}