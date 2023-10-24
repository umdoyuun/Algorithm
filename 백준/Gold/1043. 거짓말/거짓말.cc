#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int parent[51];
int n, m, t;
int result;
vector<vector<int>> party;
vector<int> V;

int getParent(int x) {
	if (x == parent[x]) return x;
	else return parent[x] = getParent(parent[x]);
}


void unionParent(int x, int y) {
	int px = getParent(x);
	int py = getParent(y);
	if (px != py) {
		if (px < py)
			parent[py] = parent[px];
		else
			parent[px] = parent[py];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> t;
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	int a, p, first;
	for (int i = 0; i < t; i++) {
		cin >> a;
		parent[a] = 0;
	}
	for (int i = 0; i < m; i++) {
		V.clear();
		cin >> p;
		cin >> first;
		V.push_back(first);
		for (int j = 1; j < p; j++) {
			cin >> a;
			V.push_back(a);
			unionParent(first, a);
		}
		party.push_back(V);
	}
	result = m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < party[i].size(); j++) {
			if (getParent(party[i][j]) == 0) {
				result--;
				break;
			}
		}
	}
	cout << result;
	return 0;
}